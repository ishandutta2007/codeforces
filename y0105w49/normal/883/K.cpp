// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;






const int N=200<<10;
int n;
int s[N],y[N],x[N];





int32_t main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",s+i,y+i), y[i]+=s[i];
	int mx=inf;
	for(int i=1;i<=n;i++) {
		x[i]=y[i];
		mx=min(mx,x[i]-i);
		x[i]=min(x[i],mx+i);
	}
	mx=inf;
	ll Z=0;
	for(int i=n;i>=1;i--) {
		mx=min(mx,x[i]+i);
		x[i]=min(x[i],mx-i);
		if(x[i]<s[i]) return printf("-1\n"),0;
		Z+=x[i]-s[i];
	}
	printf("%lld\n",Z);
	for(int i=1;i<=n;i++) printf("%d%c",x[i]," \n"[i==n]);
}