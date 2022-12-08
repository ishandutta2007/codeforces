#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 300000; 

int n, S; 
int s[maxn]; 
int a[maxn], b[maxn]; 
ll sum, ans; 
vector<pair<ll,ll>> d; 

int main() {
	cin>>n>>S; 
	sum = 0; ans = 0; d.clear(); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d%d%d", &s[i], &a[i], &b[i] ); 
		sum += s[i]; 
		ans += ll(s[i]) * b[i]; 
		d.pb({a[i]-b[i],s[i]}); 
	}
	if (sum % S > 0) d.pb({0,S-sum%S}); 
	sort(d.begin(), d.end()); 
	reverse(d.begin(), d.end()); 
	ll tot = 0; 
	ll maxd = 0; 
	ll num = 0; 
	for (auto p : d) {
		if (num + p.sec >= S) {
			maxd = max(maxd, ll(S-num)*p.fir+tot); 
			maxd = max(maxd, ll((p.sec+num)/S*S-num)*p.fir+tot); 
		}
		tot += p.fir * p.sec; 
		num = (num + p.sec) % S; 
	}
	cout<<ans+maxd<<endl; 
	return 0;
}