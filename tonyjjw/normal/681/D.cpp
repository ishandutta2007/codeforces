#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN = 100000 + 10;

int N,M;
int chk[MN];
int depth[MN];
int back[MN];
int bd[MN];
int root[MN];
vector<int> sons[MN],ans;
bool flag=false;

void dfs(int n){
	for(auto &p:sons[n]){
		depth[p] = depth[n]+1;
		dfs(p);
	}
	for(auto &p:sons[n]){
		bd[n] = min(bd[n],bd[p]);
	}
	if(back[n]!=-1){
		bd[n] = min(bd[n],depth[back[n]]);
	}
	if(chk[n]){
		if(bd[n]<depth[n]){ flag=true;}
		ans.push_back(n);
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);a--,b--;
		sons[a].push_back(b);
		root[b]=1;
	}
	for(int i=0;i<N;i++) bd[i]=1e9, back[i]=-1;
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a); a--;
		chk[a]=1;
		back[i]=a;
	}
	for(int i=0;i<N;i++)if(!root[i]){
		dfs(i);
	}
	if(flag){
		puts("-1");
		return 0;
	}
	printf("%d\n",ans.size());
	for(auto &n:ans){
		printf("%d\n",n+1);
	}
	return 0;
}