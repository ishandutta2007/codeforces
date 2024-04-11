#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 5;

struct EDGE{
	EDGE(){}
	EDGE(int t,ll c):t(t),c(c){}
	int t;
	ll c;
};
vector<EDGE> E[MN];

int N;
int A[MN];
int sz[MN],chk[MN];

int dfs(int n,ll len){
	int ret=0;
	chk[n]=1;
	sz[n]=1;
	for(auto &e:E[n])if(chk[e.t]==0){
		ret += dfs(e.t,max(0ll,len+e.c));
		sz[n] += sz[e.t];
	}
	if(len>A[n]) return sz[n];
	return ret;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(int it=0;it<N-1;it++){
		II(b)II(c); b--;
		int a = it+1;
		E[a].emplace_back(b,(ll)c);
		E[b].emplace_back(a,(ll)c);
	}
	printf("%d\n",dfs(0,0ll));
	return 0;
}