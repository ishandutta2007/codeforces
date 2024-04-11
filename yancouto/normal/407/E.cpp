#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;

int mx = 0;
int k, d;

const int N = 212345;

ll tr[N << 2], lz[N << 2];
void unlaze(int i, int l, int r) {
	if(lz[i] == 0) return;
	tr[i] += lz[i];
	if(l != r)
		lz[2 * i] += lz[i], lz[2 * i + 1] += lz[i];
	lz[i] = 0;
}

void build(int i, int l, int r) {
	lz[i] = 0;
	tr[i] = (r - l + 1);
	if(l == r) return;
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
}

void add(int i, int l, int r, int ql, int qr, ll v) {
	if(i == 1) debug("(%d, %d) += %lld\n", ql, qr, v);
	unlaze(i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		lz[i] = v;
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	add(2 * i, l, m, ql, qr, v);
	add(2 * i + 1, m + 1, r, ql, qr, v);
	tr[i] = min(tr[2 * i], tr[2 * i + 1]);
}

int get_lst(int i, int l, int r, int qr) {
	unlaze(i, l, r);
	if(l > qr) return -1;
	if(l == r) return tr[i] <= k? l : -1;
	int m = (l + r) / 2;
	if(r > qr) {
		int x = get_lst(2 * i + 1, m + 1, r, qr);
		if(x != -1) return x;
		return get_lst(2 * i, l, m, qr);
	}
	unlaze(2 * i, l, m);
	unlaze(2 * i + 1, m + 1, r);
	if(tr[2 * i + 1] <= k) return get_lst(2 * i + 1, m + 1, r, qr);
	else return get_lst(2 * i, l, m, qr);
}
void deb(int i, int l, int r) {
	unlaze(i, l, r);
	if(l == r) { debug("%lld ", tr[i]); return; }
	int m = (l + r) / 2;
	deb(2 * i, l, m);
	deb(2 * i + 1, m + 1, r);
}

int bstl = -1;

void solve(int off, vector<int> &v) {
	debug("\nsolve: ");
	for(int &x : v) x /= d;
	for(int &x : v) debug("%d ", x);
	debug("\n");
	n = v.size();
	build(1, 0, n - 1);
	int r = n;
	map<int, int> nx;
	stack<int> mxs, mns;
	mxs.push(n); mns.push(n);
	for(int i = n - 1; i >= 0; i--) {
		if(nx.count(v[i])) r = min(nx[v[i]], r);
		nx[v[i]] = i;
		// update
		add(1, 0, n - 1, i, r - 1, -1);
		int l = i; int val = 0;
		while(mxs.top() < r && v[mxs.top()] < v[i]) {
			add(1, 0, n - 1, l, mxs.top() - 1, v[i] - val);
			val = v[mxs.top()]; l = mxs.top();
			mxs.pop();
		}
		add(1, 0, n - 1, l, min(mxs.top(), r) - 1, v[i] - val);
		add(1, 0, n - 1, i, min(mns.top(), r) - 1, -v[i]);
		while(mns.top() < r && v[mns.top()] > v[i]) {
			l = mns.top(); val = v[mns.top()]; mns.pop();
			add(1, 0, n - 1, l, min(mns.top(), r) - 1, -(v[i] - val));
		}
		//deb(1, 0, n - 1); debug("\n");

		mxs.push(i);
		mns.push(i);
		
		debug("[%d->%d] best %d, %d\n\n", i, r-1, i, get_lst(1, 0, n - 1, r - 1));
		int ans = get_lst(1, 0, n - 1, r - 1) - i + 1;
		if(ans > mx || (ans == mx && i + off < bstl))
			mx = ans, bstl = i + off;
	}
}

int main() {
	int i, j, x, n;
	rd(n); rd(k); rd(d);
	if(d == 0) {
		int lst = INT_MAX;
		int mx = 0;
		int ct = 0;
		int bstl = -1;
		for(i = 0; i < n; i++) {
			rd(x);
			if(x != lst) ct = 0, lst = x;
			ct++;
			if(ct > mx) {
				bstl = i - ct + 1;
				mx = ct;
			}
		}
		printf("%d %d\n", bstl + 1, bstl + mx);
		return 0;
	}
	vector<int> a;
	int off = 0;
	for(i = 0; i < n; i++) {
		rd(x); x += 1000000000;
		if(!a.empty() && (a.back() % d) != (x % d)) {
			solve(off, a);
			off += a.size();
			a.clear();
		}
		a.push_back(x);
	}
	solve(off, a);
	printf("%d %d\n", bstl + 1, bstl + mx);
}