#include<cstdio>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

const int inf=1e8;

typedef pair<int,int> P;

const int di[]={1,0,-1,0};
const int dj[]={0,1,0,-1};

char field[1100][1100];
int W,H;

int dis[3][1100][1100];

void bfs(int id){
	queue<P> que;
	for(int i=1;i<=H;i++) for(int j=1;j<=W;j++){
		dis[id][i][j]=inf;
	}
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(field[i][j]=='0'+id+1){
				que.push(P(i,j));
				dis[id][i][j]=0;
			}
		}
	}
	while(!que.empty()){
		P p=que.front();
		que.pop();
		int ci=p.first,cj=p.second;
		for(int d=0;d<4;d++){
			int ni=ci+di[d],nj=cj+dj[d];
			if(field[ni][nj]=='#') continue;
			if(dis[id][ni][nj]<=dis[id][ci][cj]+1) continue;
			dis[id][ni][nj]=dis[id][ci][cj]+1;
			que.push(P(ni,nj));
		}
	}
}

int solve(){
	for(int i=0;i<3;i++) bfs(i);
	int dis01=inf,dis12=inf,dis20=inf;
	int dis012=inf;
	for(int i=1;i<=H;i++) for(int j=1;j<=W;j++){
		dis01=min(dis01,dis[0][i][j]+dis[1][i][j]-1);
		dis12=min(dis12,dis[1][i][j]+dis[2][i][j]-1);
		dis20=min(dis20,dis[2][i][j]+dis[0][i][j]-1);
		dis012=min(dis012,dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-2);
	}
	int ans=inf;
	ans=min(ans,dis01+dis12);
	ans=min(ans,dis12+dis20);
	ans=min(ans,dis20+dis01);
	ans=min(ans,dis012);
	return ans;
}

char ch[1010];

int main(){
	scanf("%d%d",&H,&W);
	for(int i=0;i<=H+1;i++) for(int j=0;j<=W+1;j++){
		field[i][j]='#';
	}
	for(int i=0;i<H;i++){
		scanf("%s",ch);
		for(int j=0;j<W;j++){
			field[i+1][j+1]=ch[j];
		}
	}
	int ans=solve();
	if(ans>1e6) ans=-1;
	printf("%d\n",ans);
	return 0;
}