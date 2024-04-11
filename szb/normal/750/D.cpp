#include <cstdio>
using namespace std;
struct state{
	int x,y,z,t;
};
bool vis[302][302][152][4],qaq[302][302];
int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,-1,1,-1,1};
int to[8][2]={{5,7},{4,5},{4,6},{6,7},{1,2},{0,1},{2,3},{0,3}};
state q[10000002];
int is[151];
int l=1,r=0;
void p(state u){
	if (vis[u.x][u.y][u.z][u.t])
		return;
	q[++r]=u;
	vis[u.x][u.y][u.z][u.t]=qaq[u.x][u.y]=1;
}
int n;
int t[31],sum[31];
void bfs(state s){
	p(s);
	while(l<=r){
		state w=q[l++];
		if (w.z==sum[n])
			continue;
		if (is[w.z]<2){
			if (is[w.z]){
				for(int i=0;i<2;i++){
					int tat=to[w.t][i];
					p((state){w.x+dx[tat],w.y+dy[tat],w.z+1,tat-4});
				}
			}else{
				for(int i=0;i<2;i++){
					int tat=to[w.t+4][i];
					p((state){w.x+dx[tat],w.y+dy[tat],w.z+1,tat});
				}
			}
		}else if (is[w.z]==3)
			p((state){w.x+dx[w.t],w.y+dy[w.t],w.z+1,w.t});
		else p((state){w.x+dx[w.t+4],w.y+dy[w.t+4],w.z+1,w.t});
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",t+i),sum[i]=sum[i-1]+t[i];
		is[sum[i]]=i%2;
		for(int j=sum[i-1]+1;j<sum[i];j++)
			is[j]=i%2+2;
	}
	bfs((state){150,150,1,0});
	int ans=0;
	for(int i=0;i<=300;i++)
		for(int j=0;j<=300;j++)
			ans+=qaq[i][j];
	printf("%d",ans);
}