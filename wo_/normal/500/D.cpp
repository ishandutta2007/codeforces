#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[100100];
int us[100100],vs[100100];
int ls[100100];
double coe[100100];
int N;

int sz[100100];

void dfs(int v,int p){
	sz[v]=1;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		dfs(u,v);
		sz[v]+=sz[u];
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		scanf("%d%d%d",us+i,vs+i,ls+i);
		us[i]--;vs[i]--;
		G[us[i]].push_back(vs[i]);
		G[vs[i]].push_back(us[i]);
	}
	dfs(0,-1);
	for(int i=0;i<N-1;i++){
		int u=us[i],v=vs[i];
		long long s=min(sz[u],sz[v]);
		long long t=N-s;
		long long n=N;
		long long den=n*(n-1)*(n-2)/6;
		long long num=t*(s*(s-1))/2;
		num+=s*(t*(t-1))/2;
		coe[i]=(double)num/den*2;
	}
	double ans=0;
	for(int i=0;i<N-1;i++){
		ans+=coe[i]*ls[i];
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int r,w;
		scanf("%d%d",&r,&w);
		r--;
		int x=ls[r]-w;
		ans-=((double)x*coe[r]);
	//	printf("%d %d %d\n",r,ls[r],w);
		printf("%.9f\n",ans);
		ls[r]=w;
	}
	return 0;
}