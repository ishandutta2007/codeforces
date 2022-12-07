#include<bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> e[N];
int n,vis[N],ans;

void dfs(int x,int fa){
	int sum=0;
	for (auto i:e[x])
		if (i!=fa){
			dfs(i,x);
			sum+=(!vis[i]); 
		}
	if (x!=1&&sum)
		++ans,vis[x]=1;
}
void solve(){
	scanf("%d",&n);
	ans=0;
	for (int i=1;i<=n;i++){
		e[i].resize(0);
		vis[i]=0;
	}
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	int flg=0;
	for (auto i:e[1])
		if (!vis[i]) flg=1;
	printf("%d\n",n-2*ans-flg); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}