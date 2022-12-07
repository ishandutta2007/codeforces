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
const int mo=1000000007;
const int N=1005;
int vis[N][1<<12],T;
int f[N][1<<12];
struct Tree{
	vector<int> e[N],c[N];
	int sz[N],hsh[N],n;
	void init(){
		scanf("%d",&n);
		For(i,1,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].PB(y); e[y].PB(x);
		}
	}
	void dfs(int x,int fa){
		hsh[x]=0;
		c[x].resize(0);
		for (auto i:e[x]) if (i!=fa)
			c[x].PB(i),dfs(i,x),hsh[x]|=1<<(i-1);
	}
}a,b;
int dfs(int x,int y,int v){
	//cout<<x<<' '<<y<<' '<<v<<endl;
	if (y<0) return !v;
	int to=a.c[x][y];
	if (vis[to][v]==T)
		return f[to][v];
	vis[to][v]=T;
	int &ans=f[to][v];
	ans=dfs(x,y-1,v);
	For(k,0,b.n-1) if (v&(1<<k))
		ans=(ans+1ll*dfs(x,y-1,v^(1<<k))*dfs(to,a.c[to].size()-1,b.hsh[k+1]))%mo;
	return ans;
}
int count(){
	int ans=0;
	a.dfs(1,0);
	For(i,1,b.n){
		b.dfs(i,0); ++T;
		For(j,1,a.n) ans=(ans+dfs(j,a.c[j].size()-1,b.hsh[i]))%mo;
	}
	return ans;
}
int Inv(int x){
	return x<=1?1:1ll*Inv(mo%x)*(mo-mo/x)%mo; 
}
int main(){
	a.init();
	b.init();
	int ans=count();
	a=b;
	int Ans=count();
	//cout<<ans<<' '<<Ans<<endl; 
	printf("%lld\n",1ll*ans*Inv(Ans)%mo);
}