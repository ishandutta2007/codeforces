//*

#include<stdio.h>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
#define MN 100000
#define MM 2000000

vector<int> E[MN];
vector<int> C[MM+1];
vector<int> B[MN+1];

int N,Q;
int chk[MM+1],pos[MM+1];
int A[MN],V[MN];
int ans[MN];
int d[MN];

void dfs(int n,int c){
	d[n]=c,V[n]=1;
	int i;
	ans[n]=-2;
	for(i=0;i<C[A[n]].size();i++){
		if(pos[C[A[n]][i]]!=-1 && (ans[n]==-2 || d[ans[n]]<d[pos[C[A[n]][i]]])){
			ans[n]=pos[C[A[n]][i]];
		}
	}
	B[n].clear();
	for(i=0;i<C[A[n]].size();i++){
		B[n].push_back(pos[C[A[n]][i]]);
		pos[C[A[n]][i]]=n;
	}
	for(i=0;i<E[n].size();i++){
		if(V[E[n][i]])continue;
		dfs(E[n][i],c+1);
	}
	for(i=0;i<C[A[n]].size();i++){
		pos[C[A[n]][i]]=B[n][i];
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&Q);
	int i,j,a,b,t;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N-1;i++){
		scanf("%d%d",&a,&b),--a,--b;
		E[a].push_back(b),E[b].push_back(a);
	}
	for(i=2;i<=MM;i++){
		if(chk[i])continue;
		for(j=i;j<=MM;j+=i){
			chk[j]=1;
			C[j].push_back(i);
		}
	}
	for(i=0;i<=MM;i++)pos[i]=-1;
	dfs(0,0);
	for(i=0;i<Q;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&a),--a;
			printf("%d\n",ans[a]+1);
		}
		else{
			scanf("%d%d",&a,&b),--a;
			for(j=0;j<=MM;j++)pos[j]=-1;
			for(j=0;j<N;j++)V[j]=0;
			A[a]=b;
			dfs(0,0);
		}
	}
	return 0;
}

//*/