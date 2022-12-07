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
const int N=200005;
vector<pii> vec[N];
int n,fa[N],fav[N];
vector<int> opt[N][2];
int get(int x){
	if (x==fa[x]) return x;
	int t=fa[x];
	fa[x]=get(fa[x]);
	fav[x]^=fav[t];
	return fa[x]; 
}
void merge(int x,int y,int c){
	//cout<<x<<' '<<y<<' '<<c<<endl;
	int px=get(x),py=get(y);
	if (px==py) assert(!(fav[x]^fav[y]^c));
	else{
		fa[px]=py;
		fav[px]=fav[x]^fav[y]^c;
	}
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) vec[i].resize(0);
	For(c,0,1) For(i,1,n){
		int x;
		scanf("%d",&x);
		vec[x].PB(pii(c,i));
	}
	For(i,1,n)
		if (vec[i].size()!=2){
			puts("-1");
			return;
		}
	For(i,1,n) fa[i]=i,fav[i]=0;
	For(i,1,n){
		pii p1=vec[i][0],p2=vec[i][1];
		merge(p1.se,p2.se,p1.fi^p2.fi^1);
	}
	For(i,1,n)
		For(c,0,1)
			opt[i][c].resize(0);
	For(i,1,n){
		get(i);
		opt[fa[i]][fav[i]].PB(i);
	}
	int ans=0;
	For(i,1,n)
		if (fa[i]==i)
			ans+=min(opt[i][0].size(),opt[i][1].size());
	printf("%d\n",ans);
	For(i,1,n)
		if (fa[i]==i){
			int c=(opt[i][0].size()>opt[i][1].size());
			for (auto j:opt[i][c]) printf("%d ",j);
		} 
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}