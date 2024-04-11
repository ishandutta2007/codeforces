//
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 222222;
const int mod = 1e9+7;
vector<int> v[N],g[N];
int indeg[N],vis[N];
int dfsv(int u,int fa){
	if(vis[u])
		return 1;
	vis[u]=1;
	int i,s,x,t;
	s=v[u].size();
	t=1;
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x!=fa)
			t+=dfsv(x,u);
	}
	return t;
}

void dfsg(int u){
	if(vis[u])
		return;
	vis[u]=1;
	int i,s,x,t;
	s=g[u].size();
	for(i=0;i<s;i=i+1){
		x=g[u][i];
		if(!vis[x])
			dfsg(x);
	}
}

int main()
{
	int n,i,x,y;
	LL ans;
	ans=1;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		if(x==y){
			vis[x]=2;
			continue;
		}
		v[y].push_back(x);
		indeg[x]++;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(i=1;i<=N;i=i+1)
		if(vis[i]==2)
			vis[i]=0,dfsg(i);
	for(i=1;i<=N;i=i+1){
		if(!indeg[i]&&g[i].size()){
			//cout<<i<<' ';
			ans=ans*dfsv(i,0)%mod;
		}
	}
	for(i=1;i<=N;i=i+1){
		if(!vis[i]&&g[i].size()){
			//cout<<i<<endl;
			dfsg(i);
			ans=ans*2%mod;
		}
	}
	cout<<ans%mod<<endl;
	return 0;
}