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
const int N=105;
struct edge{
	int to,next;
}e[N*2];
int n,K,f[N][N],tmp[N];
int head[N],tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	f[x][0]=f[x][K+1]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			memset(tmp,0,sizeof(tmp));
			For(j,0,2*K+1) For(k,0,2*K+1){
				int nv=(j+k+1>2*K+1?max(j,k+1):min(j,k+1));
				tmp[nv]=(tmp[nv]+1ll*f[x][j]*f[e[i].to][k])%mo;
			}
			memcpy(f[x],tmp,sizeof(f[x]));
		}
}
int main(){
	scanf("%d%d",&n,&K);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	int ans=0;
	For(i,0,K) ans=(ans+f[1][i])%mo;
	printf("%d\n",ans);
}