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
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 10009;
int a[N]; ll q[N];
int mdc(int a, int b) {
	if(b == 0) return a;
	return mdc(b, a % b);
}

ll fexp(ll p, ll e) {
	ll resp = 1;
	for(; e; e >>= 1) {
		if(e & 1) resp = mod(resp * p);
		p = mod(p * p);
	}
	return resp;
}

int main() {
	int n, m, p, x, i, j;
	scanf("%d %d %d", &n, &m, &p);
	vector<int> ds;
	modn = p;
	p--;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int t = p;
	for(i = 0; i < m; i++) {
		scanf("%d", &x);
		t = mdc(t, x);
	}
	for(i = 1; i * i < p; i++)
		if((p % i) == 0) {
			ds.pb(i);
			ds.pb(p / i);
		}
	if(i * i == p) ds.pb(i);
	sort(ds.begin(), ds.end());
	for(i = 0; i < n; i++) {
		for(j = 0; fexp(a[i], ds[j]) != 1; j++);
		q[i] = mdc(p / ds[j], p / t);
	}
	p /= t;
	sort(q, q + n);
	int rs = unique(q, q + n) - q;
	ds.clear();
	for(i = 0; i < rs; i++)
		ds.pb(q[i]);
	for(i = 0; i < rs; i++)
		for(j = i + 1; j < ds.size(); j++)
			if((ds[j] % q[i]) == 0)
				ds.erase(ds.begin() + (j--));
	for(i = 0; i < ds.size(); i++)
		q[i] = ds[i];
	rs = ds.size();
	ll tot = 0;
	for(i = 1; i < (1 << rs); i++) {
		ll r = 1;
		for(j = 0; j < rs; j++)
			if(i & (1 << j))
				r = r * q[j] / mdc(r, q[j]);
		if(__builtin_popcount(i) & 1) tot += p/r;
		else tot -= p/r;
	}
	printf("%d\n", int(tot));
}