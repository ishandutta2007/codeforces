#include<bits/stdc++.h>
using namespace std;
int T,n,a[100100];
vector<int>v[100100];
void dfs(int x,int fa,int sum){
	for(auto y:v[x])if(y!=fa)a[y]=sum;
	a[x]-=sum*(v[x].size()-1);
	for(auto y:v[x])if(y!=fa)dfs(y,x,sum+a[x]+sum*(v[x].size()-2));
}
void mina(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	a[1]=-v[1].size();for(auto y:v[1])a[y]=1;
	for(auto y:v[1])dfs(y,1,-1);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
	for(int i=1;i<=n;i++)v[i].clear();
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}