#include "bits/stdc++.h"
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pii;
const int P=1000000007,N=1000005;
ui seed[] = {213133213, 8868841, 4819433, 12219391, 201174517};
ui lastseed = 2276797313ll;
inline ll num (){
	ll res = (ll)seed[0] * seed[1]%P * seed[2] * seed[3]%P * seed[4] + lastseed + seed[2]^481943312;
	seed[0] = seed[1], seed[1] = seed[2], seed[2] = seed[3], seed[3] = seed[4];
	seed[4] = (ll) lastseed * seed[3] % P + seed[0] + 1033131; lastseed = lastseed * res + 1;
	return res<0 ? ~res : res;
}
int n,m,fac[N],l,a[N],b,t,ans;
pii s[N]; ll r[N];
int main(){
	scanf ("%d%d",&n,&m); fac[0]=1;
	for (int i=1; i<=m; i++) fac[i]=(ll)fac[i-1]*i%P;
	for (int i=1; i<=n; i++) {
		scanf ("%d",&l);
		for (int j=1; j<=l; j++) scanf("%d",&a[j]); a[l+1]=0;
		sort (a+1, a+l+1); b=1, t=0;
		for (int j=1; j<=l; j++) if (a[j] != a[j+1]) s[++t] = mp(j-b+1,a[j]), b=j+1;
		sort (s+1, s+t+1); ll h;
		for (int j=1; j<=t; j++) {
			if (s[j].first != s[j-1].first || j==1) h=num();
			r[s[j].second] ^= h;
		}
	}
	sort (r+1, r+m+1); b=ans=1;
	for (int i=1; i<=m; i++) if (r[i] != r[i+1] || i==m)
		ans = (ll)ans*fac[i-b+1]%P, b=i+1;
	printf ("%d\n",ans); 
	return 0;
}