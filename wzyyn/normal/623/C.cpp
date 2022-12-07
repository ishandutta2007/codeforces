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
const int N=100005;
int n;
pii a[N];
int pmx[N],pmn[N];
int smx[N],smn[N];
ll sqr(int x){
	return 1ll*x*x;
}
bool check(ll v){
	int l=1,r=1;
	//cout<<"CHK "<<v<<endl;
	for (;a[l].fi<=0&&l<=n;++l){
		r=max(r,l);
		for (;r!=n&&sqr(a[r+1].fi-a[l].fi)<=v&&abs(a[r+1].fi)<=abs(a[l].fi);++r);
		for (;abs(a[r].fi)>abs(a[l].fi);--r);
		int mxy=max(pmx[l-1],smx[r+1]);
		int mny=min(pmn[l-1],smn[r+1]);
		if (sqr(mxy-mny)<=v&&max(sqr(a[l].fi),sqr(a[r].fi))+max(sqr(mxy),sqr(mny))<=v)
			return 1;
	}
	l=n; r=n;
	for (;a[r].fi>=0&&r>=1;--r){
		l=min(l,r);
		for (;l!=1&&sqr(a[l-1].fi-a[r].fi)<=v&&abs(a[l-1].fi)<=abs(a[r].fi);--l);
		for (;abs(a[l].fi)>abs(a[r].fi);++l);
		int mxy=max(pmx[l-1],smx[r+1]);
		int mny=min(pmn[l-1],smn[r+1]);
		//cout<<l<<' '<<r<<' '<<v<<' '<<mxy<<' '<<mny<<endl;
		if (sqr(mxy-mny)<=v&&max(sqr(a[l].fi),sqr(a[r].fi))+max(sqr(mxy),sqr(mny))<=v)
			return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1);
	pmx[0]=-(1<<30); pmn[0]=(1<<30);
	smx[n+1]=-(1<<30); smn[n+1]=(1<<30);
	For(i,1,n){
		pmx[i]=max(pmx[i-1],a[i].se);
		pmn[i]=min(pmn[i-1],a[i].se);
	}
	Rep(i,n,1){
		smx[i]=max(smx[i+1],a[i].se);
		smn[i]=min(smn[i+1],a[i].se);
	}
	ll ans=sqr(a[n].fi-a[1].fi);
	ans=min(ans,sqr(pmx[n]-pmn[n]));
	//cout<<ans<<endl;
	ll l=0,r=ans-1;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}