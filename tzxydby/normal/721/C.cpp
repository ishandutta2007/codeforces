#include<bits/stdc++.h>

#define maxn 5010
#define MAX 1000000010

using namespace std;

int n,m,T;

int deg[maxn];

struct Edge{
	int to,dis;Edge *next;
};
Edge *E[maxn],Pr[maxn];int Es;
void addedge(int u,int v,int w){
	Pr[++Es].to=v;Pr[Es].dis=w;Pr[Es].next=E[u];E[u]=&Pr[Es];deg[v]++;
}

int f[maxn][maxn],Fr[maxn][maxn];

queue<int> Q;

void Work(){
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)f[i][j]=MAX;
	f[n][1]=0;
	for(int i=1;i<=n;i++)if(!deg[i])Q.push(i);
	while(!Q.empty()){int u=Q.front();Q.pop();
		for(Edge *P=E[u];P;P=P->next){
			for(int j=1;j<n;j++)
				if(f[u][j]+P->dis<f[P->to][j+1])
					f[P->to][j+1]=f[u][j]+P->dis,Fr[P->to][j+1]=u;
			if(!--deg[P->to])Q.push(P->to);
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)if(f[1][i]<=T)ans=i;
	printf("%d\n",ans);
	int now=1;
	for(int i=ans;i;i--)printf("%d ",now),now=Fr[now][i];
}

void Init(){
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(v,u,w);
	}
}

int main(){
	Init();
	Work();
	return 0;
}