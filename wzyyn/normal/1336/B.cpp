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
int nr,ng,nb;
int r[N],g[N],b[N];
ll SQ(ll x){
	return x*x;
}
void upd(int *a,int *b,int *c,int na,int nb,int nc,ll &ans){
	For(i,1,na){
		int p1=lower_bound(b+1,b+nb+1,a[i])-b;
		int p2=upper_bound(c+1,c+nc+1,a[i])-c-1;
		if (p1>nb||p2<1) continue;
		ans=min(ans,SQ(a[i]-b[p1])+SQ(a[i]-c[p2])+SQ(b[p1]-c[p2]));
	}
}
void solve(){
	scanf("%d%d%d",&nr,&ng,&nb);
	For(i,1,nr) scanf("%d",&r[i]);
	For(i,1,ng) scanf("%d",&g[i]);
	For(i,1,nb) scanf("%d",&b[i]);
	sort(r+1,r+nr+1);
	sort(b+1,b+nb+1);
	sort(g+1,g+ng+1);
	ll ans=1ll<<62;
	upd(r,b,g,nr,nb,ng,ans);
	upd(r,g,b,nr,ng,nb,ans);
	upd(g,r,b,ng,nr,nb,ans);
	upd(g,b,r,ng,nb,nr,ans);
	upd(b,r,g,nb,nr,ng,ans);
	upd(b,g,r,nb,ng,nr,ans);
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}