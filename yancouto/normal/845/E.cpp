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
#	define debug(args...) {}
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

const int N = 1123;
ll n, m;
ll k;
ll fi[N], fj[N];

bool all(ll x, ll l) {
	vector<ll> st;
	for(int i = 0; i < k; i++) {
		if(fj[i] - x <= l && fj[i] + x >= l)
			st.push_back(fi[i] - x);
	}
	st.pb(n);
	sort(st.begin(), st.end());
	if(st.empty() || st.front() > 0) return false;
	ll sz = 2 * x + 1;
	for(int i = 1; i < st.size(); i++)
		if(st[i] - st[i - 1] > sz)
			return false;
	return true;
}

bool go(ll x, ll v[2]) {
	vector<ll> pos;
	pos.pb(0);
	pos.pb(m - 1);
	for(int i = 0; i < k; i++)
		pos.pb(fj[i] + x + 1),
		pos.pb(fj[i] - x - 1);
	sort(pos.begin(), pos.end());
	for(ll j : pos)
		if(j >= 0 && !all(x, j)) {
			v[0] = j;
			break;
		}
	reverse(pos.begin(), pos.end());
	for(ll j : pos)
		if(j < m && !all(x, j)) {
			v[1] = j;
			break;
		}
}

ll is[2], js[2];
bool ok(ll x) {
	//printf("ok(%d)\n", x);
	go(x, js);
	for(int i = 0; i < k; i++)
		swap(fi[i], fj[i]);
	swap(n, m);
	// switch
	go(x, is);
	for(int i = 0; i < k; i++)
		swap(fi[i], fj[i]);
	swap(n, m);
	// switch
	//printf("i[%d,%d] x j[%d,%d]\n", is[0], is[1], js[0], js[1]);
	if(is[0] >= n || js[0] >= m) return true;
	ll mx = max(is[1] - is[0], js[1] - js[0]) + 1;
	return 2 * x + 1 >= mx;
}

int main() {
	int i, j;
	rd(n); rd(m); rd(k);
	for(i = 0; i < k; i++)
		rd(fi[i]), rd(fj[i]), fi[i]--, fj[i]--;
	ll l = 0, r = 1000000007;
	while(l < r) {
		ll m = (l + r) / 2;
		if(ok(m)) r = m;
		else l = m + 1;
	}
	cout << l << endl;
}