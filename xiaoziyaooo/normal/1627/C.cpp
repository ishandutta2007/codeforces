#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=500005;
int n,T;
int deg[maxn],ans[maxn],rec[maxn];
vector<int>v[maxn],w[maxn];
void dfs(int x,int last,int d){
	ans[rec[x]]=d==0? 2:3;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=last)
			rec[v[x][i]]=w[x][i],dfs(v[x][i],x,d^1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1,x,y;i<n;i++)
			scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x),w[x].push_back(i),w[y].push_back(i),deg[x]++,deg[y]++;
		int rt=0,flg=0;
		for(int i=1;i<=n;i++){
			if(deg[i]==1)
				rt=i;
			else if(deg[i]>2)
				flg=1;
		}
		if(flg)
			puts("-1");
		else{
			dfs(rt,0,0);
			for(int i=1;i<n;i++)
				printf("%d ",ans[i]);
			puts("");
		}
		for(int i=0;i<=n;i++)
			v[i].clear(),w[i].clear(),deg[i]=0;
	}
	return 0;
}