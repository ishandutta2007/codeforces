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
const int N=500005;
const int mo=1000000007;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
}p[N*2];
ll v[N*2],x[N*2],y[N*2];
int n,ans;
ll S,SS;
ll plain(int l,int r){
	ll ans=v[r-1]-v[l-1];
	return ans-p[r]*p[l];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);
	For(i,1,n) p[i+n]=p[i];
	For(i,1,n) S+=p[i+1]*p[i];
	For(i,1,n){
		v[i]=v[i+n]=p[i+1]*p[i];
		x[i]=x[i+n]=p[i].x;
		y[i]=y[i+n]=p[i].y;
	}
	For(i,1,n*2) v[i]=v[i]+v[i-1];
	For(i,1,n*2) x[i]=x[i]+x[i-1];
	For(i,1,n*2) y[i]=y[i]+y[i-1];
	int l=1,r=2,pr=0,su=n-1,prS=0,suS=0;
	For(i,2,n) suS=(1ll*suS+(v[n]-v[i-1])%mo+mo)%mo;
	for (;l<=n;l++){
		for (;r+1!=l+n;++r){
			ll val=plain(l,r);
			//printf("VAL %d %d %lld\n",l,r,val);
			if (val>=(S+1)/2) break;
			prS=(1ll*prS+(v[r-1]  -v[l-1])%mo+mo)%mo;
			suS=(1ll*suS-(v[l+n-1]-v[r-1])%mo+mo)%mo;
			pr++; su--;
		}
		ll vpr=1ll*(y[r-1]-y[l])%mo*p[l].x%mo-1ll*(x[r-1]-x[l])%mo*p[l].y%mo;
		ll vsu=1ll*(y[l+n-1]-y[r-1])%mo*p[l].x%mo-1ll*(x[l+n-1]-x[r-1])%mo*p[l].y%mo;
		vpr=(1ll*prS+mo+vpr%mo)%mo;
		vsu=(1ll*suS+mo-vsu%mo)%mo;
		//printf("%d %d %d %d %lld %d %d %lld %lld\n",l,r,pr,prS,vpr,su,suS,vsu,S);
		ans=(ans+1ll*S%mo*pr%mo+mo-2ll*vpr%mo)%mo;
		ans=(ans+1ll*S%mo*su%mo+mo-2ll*vsu%mo)%mo;
		prS=(1ll*prS+mo-1ll*(v[l]-v[l-1])%mo*pr%mo)%mo; pr--;
		su++; suS=(1ll*suS+mo+1ll*(v[l]-v[l-1])%mo*su%mo)%mo;// su++;
		//suS=(1ll*suS+mo+(v[l+n]-v[r])%mo)%mo;
	}
	ans=1ll*ans*(mo+1)/2%mo;
	ans=(ans+mo-1ll*S%mo*n%mo)%mo;
	printf("%d\n",ans);
}
/*
5
2 4
2 7
5 7
5 4
3 -2
*/