#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=111111;
//head
#define maxn 110
#define maxk 45
#define mod 1000000007
int n,k;
vector<int> G[maxn];
int f[maxn][maxk],t[maxk];
int ans;
void dfs(int u,int fa){
	f[u][0]=f[u][k+1]=1;
	re(i,0,G[u].size())if(G[u][i]!=fa){
		int v=G[u][i];
		dfs(v,u);
		memset(t,0,sizeof t);
		for(int x=0;x<=(k<<1|1);x++)
			for(int y=0;y<=k<<1;y++)
				if(x+y<=k<<1) (t[min(x,y+1)]+=1LL*f[u][x]*f[v][y]%mod)%=mod;
				else (t[max(x,y+1)]+=1LL*f[u][x]*f[v][y]%mod)%=mod;
		memcpy(f[u],t,sizeof t);
	}
}
int main(){
	read(n,k);
	rep(i,1,n-1){
		int u,v;read(u,v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	rep(i,0,k)(ans+=f[1][i])%=mod;
	printf("%d\n",ans);
	return 0;
}