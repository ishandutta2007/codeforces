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
const int N=100005,M=205;
struct edge{
	int to,next;
}e[N*2];
int head[N],sz[N],tot;
int P[N],S[M][M],n,K;
int f[N][M],tmp[M],sum[M],ans;
void init(){
	P[0]=S[0][0]=1;
	For(i,1,N-1) P[i]=2ll*P[i-1]%mo;
	For(i,1,M-1) For(j,1,i)
		S[i][j]=1ll*j*(S[i-1][j-1]+S[i-1][j])%mo;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	f[x][0]=2;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			For(j,0,min(sz[x],K))
				For(k,0,min(sz[e[i].to],K-j))
					tmp[j+k]=(tmp[j+k]+1ll*f[x][j]*f[e[i].to][k])%mo;
			For(j,0,min(sz[e[i].to],K)) sum[j]=(sum[j]+mo-f[e[i].to][j])%mo;
			sz[x]+=sz[e[i].to];
			For(j,0,min(sz[x],K))
				f[x][j]=tmp[j],tmp[j]=0;
		}
	++sz[x];
	For(j,0,min(sz[x],K)) sum[j]=(sum[j]+f[x][j])%mo;
	Rep(j,min(sz[x],K),1) f[x][j]=(f[x][j]+f[x][j-1])%mo;
	f[x][1]=(f[x][1]+mo-1)%mo;
}
int main(){
	init();
	scanf("%d%d",&n,&K);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x); 
	}
	dfs(1,0);
	For(i,1,K) ans=(ans+1ll*sum[i]*S[K][i])%mo;
	printf("%d\n",ans);
}