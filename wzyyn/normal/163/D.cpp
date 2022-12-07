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
ll v,ans,A,B,C,va,vb,vc,lim,limm,a[65],b[65],n;
void dfs2(int x,ll y){
	if (y>limm) return;
	if (x>n){
		vb=y; vc=v/va/vb;
		if (2*(va*vb+va*vc+vb*vc)<=ans)
			ans=2*(va*vb+va*vc+vb*vc),A=va,B=vb,C=vc;
		return;
	}
	if (b[x]) --b[x],dfs2(x,y*a[x]),++b[x];
	dfs2(x+1,y);
}
void dfs1(int x,ll y){
	if (y>lim) return;
	if (x>n){
		va=y;
		limm=pow(v/y,1.0/2)+1e-8;
		if (2*(limm*limm+limm*y+limm*y)<ans)
			dfs2(1,1);
		return;
	}
	if (b[x]) --b[x],dfs1(x,y*a[x]),++b[x];
	dfs1(x+1,y);
}
void solve(){
	v=1;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%lld%lld",&a[i],&b[i]);
		For(j,1,b[i]) v*=a[i];
	} 
	ans=1ll<<62;
	lim=pow(v,1.0/3)+1e-8; dfs1(1,1);
	//cout<<lim<<endl;
	printf("%lld %lld %lld %lld\n",ans,A,B,C);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}