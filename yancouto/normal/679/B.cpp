#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
ll a[212345];
int totb; ll totv;
void brut(ll m) {
	int mx = 0;
	while(a[mx + 1] <= m) mx++;
	totb = -1;
	for(ll i = 1; i <= m; i++) {
		ll x = i;
		int tot = 0;
		for(int j = mx; j >= 0; j--)
			tot += x / a[j], x %= a[j];
		if(tot >= totb) totb = tot, totv = i;
	}
}

vector<int> v;
bool ok() {
	ll val = 0;
	for(int i = 0; i < v.size(); i++) {
		val += a[v[i]];
		if(val >= a[v[i] + 1]) return false;
	}
	return true;
}

ll m;
bool ok(int i, ll val) {
	if(val - a[v[i]] + a[v[i] + 1] > m) return false;
	v[i]++;
	bool o = ok();
	v[i]--;
	return o;
}

int main() {
	int i, j;
	scanf("%I64d", &m);
	int n = 0;
	for(ll i = 1; i < 200000; i++)
		a[n++] = i*i*i;
	if(m <= 1000ll) {
	    brut(m);
	    printf("%d %d\n", totb, int(totv));
	    return 0;
	}
	ll val = 0;
	int lst, tot = 0;
	for(int i = 0; i < n-1; i++) {
		while(val + a[i] < a[i + 1] && val + a[i] <= m)
			val += a[i], lst = i, tot++, v.pb(i);
	}
	//printf("%lld:", val); 
	//for(int x : v) printf(" %lld", a[x]); putchar('\n');
	for(int i = v.size() - 1; i >= 0; i--)
		if(ok(i, val)) {
			while(ok(i, val))
				val = val - a[v[i]] + a[v[i] + 1], v[i]++;
		}
	assert(ok());
	//printf("%lld:", val); 
	//for(int x : v) printf(" %lld", a[x]); putchar('\n');
	printf("%d %I64d\n", tot, val);
	//brut(m);
	//printf("%d %lld\n", totb, totv);
	//assert(tot == totb && val == totv);
}