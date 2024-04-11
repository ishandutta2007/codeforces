#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

const int N=55;
pll a[N];
ll f[N][N],sum[N];
int n;
bool check(ll v){
	memset(f,60,sizeof(f));
	f[0][0]=0;
	for (int i=1,j;i<=n;i=j){
		for (j=i;a[j].fi==a[i].fi&&j<=n;++j);
		For(k,i,j-1) sum[k-i+1]=sum[k-i]+1000ll*a[k].fi-1ll*v*a[k].se;
		For(k,0,n) For(l,0,min(k,j-i))
			f[j-1][(k-l)+(j-i)-l]=min(f[j-1][(k-l)+(j-i)-l],f[i-1][k]+sum[(j-i)-l]);
	}
	For(i,0,n)
		if (f[n][i]<=0) return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i].fi);
	For(i,1,n) scanf("%lld",&a[i].se);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll l=0,r=1ll<<40,ans;
	while (l<=r){
		//cout<<l<<' '<<r<<endl;
		ll mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}