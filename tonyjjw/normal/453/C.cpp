#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
#define MN 100000

using namespace std;

vector<int> E[MN];

int N,M,C[MN],st;
int path[4*MN],V[MN],S;

void visit(int n){
	C[n]=1-C[n];
	path[S++]=n+1;
}

void dfs(int n,int p){
	V[n]=1;
	visit(n);
	int i;
	for(i=0;i<E[n].size();i++){
		if(V[E[n][i]])continue;
		dfs(E[n][i],n);
		visit(n);
	}
	if(n!=st && C[n]){
		visit(p);
		visit(n);
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,a,b;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++){
		scanf("%d%d",&a,&b),--a,--b;
		E[a].push_back(b),E[b].push_back(a);
	}
	for(i=0;i<N;i++)scanf("%d",&C[i]);
	for(i=0;i<N;i++)if(C[i])break;
	st=i;
	dfs(i,-1);
	for(i=0;i<N;i++)if(i!=st && C[i])break;
	if(i<N){
		puts("-1");
		return 0;
	}
	if(!C[st]){
		printf("%d\n",S);
		for(i=0;i<S;i++)printf("%d ",path[i]);
	}
	else{
		printf("%d\n",S-1);
		for(i=1;i<S;i++)printf("%d ",path[i]);
	}
	return 0;
}