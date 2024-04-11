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
const ll N=400005;
int m,top;
ll n,k,a[N];
pll q[N];
void solve(){
	top=0;
	scanf("%lld%d%lld",&n,&m,&k);
	For(i,1,m) scanf("%lld",&a[i]);
	a[0]=0; a[++m]=n;
	Rep(i,m,1) a[i]-=a[i-1];
	ll l,r,vl,vr;
	l=1; r=n+1; vl=n+1;
	while (l<=r){
		ll mid=(l+r)/2,s=0;
		For(i,1,m) s+=a[i]/mid;
		if (s>=m+k) vl=mid,l=mid+1;
		else r=mid-1;
	}
	l=1; r=n+1; vr=n+1;
	while (l<=r){
		ll mid=(l+r)/2,s=0;
		For(i,1,m) s+=(a[i]+mid-1)/mid;
		if (s<=m+k) vr=mid,r=mid-1;
		else l=mid+1;
	}
	//For(i,1,m) cout<<a[i]<<' '; cout<<endl;
	//cout<<vl<<' '<<vr<<endl;
	For(i,1,m){
		ll tl=a[i]/vl,tr=(a[i]+vr-1)/vr;
		if (tl>=tr) continue;
		//cout<<i<<' '<<tl<<' '<<tr<<endl;
		ll pl=1ll<<60,pr=a[i]/tr;
		if (tl) pl=(a[i]+tl-1)/tl;
		q[++top]=pll(pr,pl);
	}
	sort(q+1,q+top+1);
	ll mx=vr,ans=n+1;
	For(i,1,top){
		ans=min(ans,mx-q[i].fi);
		mx=max(mx,q[i].se);
	}
	ans=min(ans,mx-vl);
	printf("%lld\n",ans);
	
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
		//freopen("1.out","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}