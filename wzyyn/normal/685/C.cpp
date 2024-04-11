#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=1000005;
ll x[N],y[N],z[N];
ll ansx,ansy,ansz;
int n;
bool check(ll mid){
	ll mn1,mn2,mn3,mn4,MN1,MN2,MN3,MN4;
	ll mx1,mx2,mx3,mx4,MX1,MX2,MX3,MX4;
	mn1=mn2=mn3=mn4=-(1ll<<62);
	mx1=mx2=mx3=mx4=(1ll<<62);
	For(i,1,n){
		mn1=max(mn1,x[i]+y[i]+z[i]-mid);
		mx1=min(mx1,x[i]+y[i]+z[i]+mid);
		mn2=max(mn2,x[i]+y[i]-z[i]-mid);
		mx2=min(mx2,x[i]+y[i]-z[i]+mid);
		mn3=max(mn3,x[i]-y[i]+z[i]-mid);
		mx3=min(mx3,x[i]-y[i]+z[i]+mid);
		mn4=max(mn4,-x[i]+y[i]+z[i]-mid);
		mx4=min(mx4,-x[i]+y[i]+z[i]+mid);
	}
	MN1=(mn1+(mn1&1))/2; MN2=(mn2+(mn2&1))/2;
	MN3=(mn3+(mn3&1))/2; MN4=(mn4+(mn4&1))/2;
	MX1=(mx1-(mx1&1))/2; MX2=(mx2-(mx2&1))/2;
	MX3=(mx3-(mx3&1))/2; MX4=(mx4-(mx4&1))/2;
	//printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",mn1,mx1,mn2,mx2,mn3,mx3,mn4,mx4);
	if (MN2+MN3<=MX1-MN4&&MX2+MX3>=MN1-MX4)
		if (MN1<=MX1&&MN2<=MX2&&MN3<=MX3&&MN4<=MX4){
			ll va2,va3,va4;
			va2=max(MN1-MX3-MX4,MN2);
			va3=max(MN1-va2-MX4,MN3);
			va4=max(MN1-va2-va3,MN4);
			ansx=va2+va3;
			ansy=va2+va4;
			ansz=va3+va4;
			//puts("ddd");
			return 1;
		}
	MN1=(mn1-(mn1&1))/2; MN2=(mn2-(mn2&1))/2;
	MN3=(mn3-(mn3&1))/2; MN4=(mn4-(mn4&1))/2;
	MX1=(mx1-2+(mx1&1))/2; MX2=(mx2-2+(mx2&1))/2;
	MX3=(mx3-2+(mx3&1))/2; MX4=(mx4-2+(mx4&1))/2;
	--MN1; --MX1;
	//printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",MN1,MX1,MN2,MX2,MN3,MX3,MN4,MX4);
	if (MN2+MN3<=MX1-MN4&&MX2+MX3>=MN1-MX4)
		if (MN1<=MX1&&MN2<=MX2&&MN3<=MX3&&MN4<=MX4){
			ll va2,va3,va4;
			va2=max(MN1-MX3-MX4,MN2);
			va3=max(MN1-va2-MX4,MN3);
			va4=max(MN1-va2-va3,MN4);
			//printf("%lld %lld %lld",va2,va3,va4);
			ansx=va2+va3+1;
			ansy=va2+va4+1;
			ansz=va3+va4+1;
			return 1;
		}
	return 0;
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
	ll l=0,r=3ll<<60,ans=0;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	//printf("%lld\n",ans);
	check(ans);
	printf("%lld %lld %lld\n",ansx,ansy,ansz);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
} 
/*
1
2
1000000000000000000
1000000000000000000
1000000000000000000
-900000000000000000
-900000000000000000
-900000000000000000
*/