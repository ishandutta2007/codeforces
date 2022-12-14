//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MM 500000
#define MN 100000
#pragma comment(linker, "/STACK:16777216")
using namespace std;

int N,M;
struct EDGE{
	int s,e;
	EDGE(){}
	EDGE(int a,int b){
		s=a;
		e=b;
	}
}edge[MM];

vector<int> E[MN];
int deg[MN];
int V[MM];
int cyc[MM],cycn;

void dfs(int n){
	while(E[n].size()){
		int p=E[n].back();
		E[n].pop_back();
		if(V[p])continue;
		EDGE &e=edge[p];
		int t=e.s+e.e-n;

		V[p]=1;
		dfs(t);
		cyc[cycn++]=p;
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&edge[i].s,&edge[i].e);
		edge[i].s--,edge[i].e--;
		deg[edge[i].s]++,deg[edge[i].e]++;
	}
	for(int i=0;i<N;i++){
		if(deg[i]&1){
			int j;
			for(j=i+1;deg[j]%2==0;j++);
			deg[i]++,deg[j]++;
			edge[M]=EDGE(i,j);
			M++;
		}
	}
	if(M&1){
		edge[M]=EDGE(0,0);
		M++;
	}
	for(int i=0;i<M;i++){
		E[edge[i].s].push_back(i);
		E[edge[i].e].push_back(i);
	}
	dfs(0);
	int f=0,n=0;
	for(int i=0;i<cycn;i++){
		int t=edge[cyc[i]].s+edge[cyc[i]].e-n;
		if(!f){
			edge[cyc[i]]=EDGE(n,t);
		}
		else{
			edge[cyc[i]]=EDGE(t,n);
		}
		f=1-f;
		n=t;
	}
	printf("%d\n",M);
	for(int i=0;i<M;i++){
		printf("%d %d\n",edge[i].s+1,edge[i].e+1);
	}
	return 0;
}
//*/