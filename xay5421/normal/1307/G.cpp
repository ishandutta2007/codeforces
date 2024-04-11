#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#define D(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int N=55,M=N*N*2;
int n,m,Q,pre[N],dis[N],len,w[N];bool vis[N];
struct ed{int nxt,to,v,c;}G[M];int lnk[N],pp=1;
void ae(int k1,int k2,int k3){
	G[++pp]=(ed){lnk[k1],k2,1,k3},lnk[k1]=pp;
	G[++pp]=(ed){lnk[k2],k1,0,-k3},lnk[k2]=pp;
}
bool spfa(){
	memset(pre,0,sizeof(pre));
	memset(dis,63,sizeof(dis));dis[1]=0;
	static int q[N];int he=0,ta=1;q[1]=1,vis[1]=1;
	while(he!=ta){
		int k1=q[++he%=N];vis[k1]=0;//printf("dis[%d]=%d\n",k1,dis[k1]);
		for(int i=lnk[k1];i;i=G[i].nxt)if(G[i].v&&dis[k1]+G[i].c<dis[G[i].to]){
			dis[G[i].to]=dis[k1]+G[i].c;
			pre[G[i].to]=i;
			if(!vis[G[i].to]){
				q[++ta%=N]=G[i].to;
				vis[G[i].to]=1;
			}
		}
	}
	return !!pre[n];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		ae(k1,k2,k3);
	}
	while(spfa()){
		for(int i=pre[n];i;i=pre[G[i^1].to])--G[i].v,++G[i^1].v;
		++len,w[len]=w[len-1]+dis[n];
	}
	scanf("%d",&Q);
	while(Q--){
		int x;scanf("%d",&x);
		double ans=1e100;
		// flow*ans-cost<=x
		// ans<=(x+cost)/flow
		for(int i=1;i<=len;++i)ans=min(ans,1.*(x+w[i])/i);
		printf("%.20f\n",ans);
	}
	return 0;
}