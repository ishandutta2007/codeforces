#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 300000 + 5;

int N,Q;
int par[MN];
int centroid[MN], sz[MN];
vector<int> sons[MN];

void dfs(int n){
	sz[n]=1;
	for(auto &p:sons[n]){
		dfs(p);
		sz[n]+=sz[p];
	}
	int maxsz=0,pp=-1;
	for(auto &p:sons[n]){
		if(maxsz<sz[p]){
			maxsz=sz[p];
			pp=p;
		}
	}
	if(2*maxsz<=sz[n]){
		centroid[n]=n;
	}
	else{
		centroid[n] = centroid[pp];
		while(2*(sz[n]-sz[centroid[n]]) > sz[n]){
			centroid[n] = par[centroid[n]];
		}
	}
}

int main(){
	scanf("%d%d",&N,&Q);
	for(int i=1;i<N;i++){
		scanf("%d",&par[i]); par[i]--;
		sons[par[i]].push_back(i);
	}
	dfs(0);
	for(int q=0;q<Q;q++){
		II(a); a--;
		printf("%d\n",centroid[a]+1);
	}
	return 0;
}