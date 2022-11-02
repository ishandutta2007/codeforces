#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 200009;

int x[N], y[N];
const int tmp = N - 1;
struct cmp {
	bool operator()(int i, int j) {
		if(y[i] != y[j]) return y[i] < y[j];
		return i < j;
	}
};

set<pii> tr[N << 2];
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

int bn;
void add_t(int i, int l, int r, int p) {
	tr[i].insert(pii(y[p], p));
	if(l == r) return;
	int m = (l + r) / 2;
	if(x[p] <= m) add_t(L(i), l, m, p);
	else add_t(R(i), m + 1, r, p);
}

void rem_t(int i, int l, int r, int p) {
	tr[i].erase(pii(y[p], p));
	if(l == r) return;
	int m = (l + r) / 2;
	if(x[p] <= m) rem_t(L(i), l, m, p);
	else rem_t(R(i), m + 1, r, p);
}

void collect(int i, int l, int r, int x1, int x2, int y1, int y2, vector<int> &v) {
	if(r < x1 || l > x2) return;
	if(l >= x1 && r <= x2) {
		auto it = tr[i].lower_bound(pii(y1, INT_MIN));
		auto it2 = tr[i].upper_bound(pii(y2, INT_MAX));
		while(it != it2) {
			v.pb(it->snd);
			++it;
		}
		return;
	}
	int m = (l + r) / 2;
	collect(L(i), l, m, x1, x2, y1, y2, v);
	collect(R(i), m + 1, r, x1, x2, y1, y2, v);
}

vector<int> pos;
int nx[N];
void proc(int p) {
	vector<int> aux;
	collect(1, 0, bn - 1, x[2*p], bn - 1, y[2*p], INT_MAX, aux);
	for(int i : aux) {
		int pp = i / 2;
		pos.pb(pp);
		rem_t(1, 0, bn - 1, i);
		nx[pp] = p;
	}
}

int b[N], d[N], can[N];
int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x[2*i], &y[2*i], &x[2*i+1], &y[2*i+1]);
		b[2*i] = x[2*i];
		b[2*i+1] = x[2*i+1];
	}
	sort(b, b + 2*n);
	bn = unique(b, b + 2*n) - b;
	for(i = 0; i < n; i++) {
		x[2*i] = lower_bound(b, b + bn, x[2*i]) - b;
		x[2*i+1] = lower_bound(b, b + bn, x[2*i+1]) - b;
		if(i != n - 1) add_t(1, 0, bn - 1, 2*i+1);
	}
	pos.pb(n - 1);
	int dist = 0;
	while(!pos.empty()) {
		dist++;
		vector<int> v;
		v.swap(pos);
		for(int u : v) {
			d[u] = dist;
			can[u] = true;
			proc(u);
		}
	}
	int ba = -1, best = INT_MAX;
	for(i = 0; i < n; i++)
		if(can[i] && x[2*i] == 0 && y[2*i] == 0 && d[i] < best) {
			best = d[i];
			ba = i;
		}
	if(ba != -1) {
		int a = ba;
		printf("%d\n", d[a]);
		while(a != n - 1) {
			printf("%d ", a + 1);
			a = nx[a];
		}
		printf("%d\n", n);
	} else
		puts("-1");
}