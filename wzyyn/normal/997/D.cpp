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
const int N=4005,M=80;
const int mo=998244353;
int n1,n2,K,ans;
int C[M][M];
void init(){
	For(i,0,M-1) C[i][0]=1;
	For(i,1,M-1) For(j,1,i)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
}
struct edge{
	int to,next;
};
struct WZP{
	edge e[N*2];
	int head[N],tot,sz[N];
	int f[N][M],F[N][M],vis[N],q[N];
	int mxv,rt,g[M],h[M];
	void add(int x,int y){
		e[++tot]=(edge){y,head[x]};
		head[x]=tot;
	}
	void dfs(int x,int fa,int n){
		sz[x]=1;
		q[++*q]=x;
		int mx=0;
		for (int i=head[x];i;i=e[i].next)
			if (!vis[e[i].to]&&e[i].to!=fa){
				dfs(e[i].to,x,n);
				sz[x]+=sz[e[i].to];
				mx=max(mx,sz[e[i].to]);
			}
		mx=max(mx,n-sz[x]);
		if (mx<mxv) mxv=mx,rt=x;
	}
	void solve(int x,int n){
		mxv=1<<30; *q=0;
		dfs(x,0,n); vis[x=rt]=1;
		f[x][0]=1; F[x][0]=1; //h[0]++;
		For(i,1,K) For(j,1,*q)
			for (int k=head[q[j]];k;k=e[k].next){
				f[q[j]][i]=(f[q[j]][i]+f[e[k].to][i-1])%mo;
				if (q[j]!=x) F[q[j]][i]=(F[q[j]][i]+F[e[k].to][i-1])%mo;
			}
		For(i,1,*q) For(j,0,K) For(k,0,K-j)
			h[j+k]=(h[j+k]+1ll*F[q[i]][j]*f[q[i]][k])%mo;
		For(i,0,K) For(j,1,*q) f[q[j]][i]=F[q[j]][i]=0;
		for (int i=head[x];i;i=e[i].next)
			if (!vis[e[i].to]) solve(e[i].to,sz[e[i].to]>sz[x]?n-sz[x]:sz[e[i].to]);
	}
	void solve(int n){
		For(i,1,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y); add(y,x);
		}
		solve(1,n);
		//For(i,0,K) cout<<h[i]<<' '; cout<<endl;
	}
}T1,T2;
int main(){
	init();
	scanf("%d%d%d",&n1,&n2,&K);
	T1.solve(n1); T2.solve(n2);
	For(i,0,K) ans=(ans+1ll*T1.h[i]*T2.h[K-i]%mo*C[K][i])%mo;
	printf("%d\n",ans);
}