#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int dis[100][100];

const int inf=1000;

int ss[100],ts[100];

//vector<int> vs[100][100][101];//[v][i][d]
vector<int> nxt[100][100];//[i][v]

bool flg[100][100];

int N,M,A,B;
int K;

int dp[100];
int mi[100];

void dfs(int v,int i){
	int tmp=-1;
	for(int j=0;j<nxt[i][v].size();j++){
		int u=nxt[i][v][j];
		dfs(u,i);
		tmp=max(tmp,mi[u]);
	}
	if(tmp==-1) return;
	else if(tmp<inf){
		mi[v]=min(mi[v],tmp);
	}
}

bool rel(){
	for(int i=0;i<K;i++){
		for(int v=0;v<N;v++) mi[v]=dp[v];
		dfs(ss[i],i);
//		for(int v=0;v<N;v++) printf("%d ",mi[v]);
//		printf("\n");
		for(int v=0;v<N;v++) if(flg[i][v]) dp[v]=min(dp[v],mi[v]+1);
	}
}

int main(){
	scanf("%d%d%d%d",&N,&M,&A,&B);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) dis[i][j]=inf;
	A--;B--;
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		dis[u][v]=1;
	}
	for(int i=0;i<N;i++) dis[i][i]=0;
	for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++){
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d%d",ss+i,ts+i);
		ss[i]--;ts[i]--;
	}
	for(int v=0;v<N;v++) for(int i=0;i<K;i++){
		int s=ss[i],t=ts[i];
		int D=dis[s][t];
		if(D==inf) continue;
		if(dis[s][v]+dis[v][t]!=D) continue;
		bool ok=true;
		for(int u=0;u<N;u++){
			if(u==v) continue;
			if(dis[s][u]!=dis[s][v]) continue;
			if(dis[s][u]+dis[u][t]==D) ok=false;
		}
		flg[i][v]=ok;
	}
	for(int i=0;i<N;i++) dp[i]=inf;
	dp[B]=0;
/*	for(int i=0;i<K;i++){
		int s=ss[i],t=ts[i];
		if(dis[s][t]==inf) continue;
		int D=dis[s][t];
		for(int v=0;v<N;v++){
			for(int u=0;u<N;u++){
				if(u==v) continue;
				//s->v->u->t
				int cd=dis[s][v]+dis[v][u]+dis[u][t];
				if(cd!=D) continue;
				int d=dis[v][u];
				vs[v][i][d].push_back(u);
			}
		}
	}
	*/
	for(int i=0;i<K;i++){
		int s=ss[i],t=ts[i];
		if(dis[s][t]==inf) continue;
		int D=dis[s][t];
		for(int v=0;v<N;v++){
			for(int u=0;u<N;u++){
				if(dis[v][u]!=1) continue;
				int d=dis[s][v]+dis[v][u]+dis[u][t];
				if(d!=D) continue;
				nxt[i][v].push_back(u);
			}
		}
	}
/*	for(int i=0;i<K;i++){
		printf("i=%d----\n",i);
		for(int v=0;v<N;v++){
			printf("%d::",v);
			for(int j=0;j<nxt[i][v].size();j++){
				printf("%d ",nxt[i][v][j]);
			}
			printf("\n");
		}
	}*/
	for(int i=0;i<150;i++) rel();
	if(dp[A]==inf){
		printf("-1\n");
	}else{
		printf("%d\n",dp[A]);
	}
	return 0;
}