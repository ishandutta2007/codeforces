#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
 
int n;
ll arr[200100];
const int MAX = 1000100;
bool sve[MAX+10];
int p;
ll pri[100100];
 
void init() {
	for (int i=2;i<=MAX;i++) {
		if (sve[i]) continue;
		pri[p++] = i;
		if (i>MAX/i) continue;
		for (int j=i*i;j<=MAX;j+=i) sve[j] = 1;
	}
}
 
ll tans[MAX+10];
ll getv(ll p) {
	ll ans = 0, v = 0;
	if (p<=MAX&&~tans[p]) return tans[p];
	for (int i=0;i<n;i++) {
		if (arr[i] <= p) ans += p - arr[i];
		else {
			v = arr[i] % p;
			ans += min(v, p - v);
		}
		if (ans>=n) {
			if (p<=MAX) tans[p] = n;
			return n;
		}
	}
	if (p<=MAX) tans[p] = ans;
	return ans;
}
 
ll gcd(ll a, ll b) {
	return a?gcd(b%a,a):b;
}
 
ll div_test(ll m) {
	ll ans = n;
	for (int i=0;i<p;i++) {
		if (m%pri[i]==0) {
			ans = min(ans,getv(pri[i]));
			while(m%pri[i]==0) m/=pri[i];
		}
	}
	if (m>1) {
		ans = min(ans,getv(m));
	}
	return ans;
}
 
int main() {
	memset(tans,-1,sizeof(tans));
	init();
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld",&arr[i]);
	int K = 80;
	ll ans = getv(2);
	srand(time(NULL));
	while(K--) {
		int r = rand()%n, s = rand()%(n-1);
		if (s>=r) s++;
		for (ll i=arr[r]-2;i<=arr[r]+2;i++) {
			for (ll j=arr[s]-2;j<=arr[s]+2;j++) {
				ll g = gcd(i,j);
				if (g>1) ans = min(ans,div_test(g));
			}
		}
	}
	printf("%lld\n",ans);
 
	return 0;
}