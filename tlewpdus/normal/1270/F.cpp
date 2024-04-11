#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int SQ = 500;

int n;
char str[200100];
vector<int> loc;
ll psum[200100];

ll di(ll a, ll b) {
	if (a>=0) return a/b;
	return (a-b+1)/b;
}
ll val(ll s, ll e, ll rem, ll m) {
	if (s>e) return 0;
	return di(e-rem,m)-di(s-1-rem,m);
}

int main() {
	scanf("%s",str+1);
	n = strlen(str+1);
	for (int i=1;i<=n;i++) str[i]-='0';
	for (int i=1;i<=n;i++) if (str[i]) loc.push_back(i);
	ll ans = 0;
	for (int i=0;i<loc.size();i++) {
		for (int j=i;j<i+SQ&&j<loc.size();j++) {
			int a = (j+1==loc.size()?n+1:loc[j+1])-loc[j]-1;
			int b = loc[i]-(i==0?0:loc[i-1])-1;
			int l = loc[j]-loc[i]+1;
			int m = j-i+1;
			for (int k=0;k<=a;k++) {
				int rem = ((m-l-k)%m+m)%m;
				ans += val(max(0,SQ*m-l-k),b,rem,m);
			}
		}
	}
	for (int k=1;k<SQ;k++) {
		for (int i=1;i<=n;i++) psum[i] = psum[i-1]+(str[i]?-k+1:1);
		vector<ll> comp;
		for (int i=0;i<=n;i++) comp.push_back(psum[i]);
		sort(comp.begin(),comp.end());
		int p = 0;
		for (int i=0;i<comp.size();i++) {
			if (i+1==comp.size()||comp[i]!=comp[i+1]) {
				ans += 1LL*(i-p)*(i-p+1)/2;
				p = i+1;
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}