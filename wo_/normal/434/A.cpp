#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
int a[100100];

vector<int> adj[100100];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<M-1;i++){
		if(a[i]==a[i+1]) continue;
		adj[a[i]].push_back(a[i+1]);
		adj[a[i+1]].push_back(a[i]);
	}
	long long ans=0;
	for(int i=0;i<M-1;i++){
		ans+=max(a[i+1]-a[i],a[i]-a[i+1]);
	}
	long long all=ans;
	for(int i=1;i<=N;i++){
		long long ini=0,best=0;
		sort(adj[i].begin(),adj[i].end());
		int s=adj[i].size();
		for(int j=0;j<adj[i].size();j++){
			ini+=(max(adj[i][j]-i,i-adj[i][j]));
			best+=(max(adj[i][j]-adj[i][s/2],adj[i][s/2]-adj[i][j]));
		}
		long long tmp=all-ini+best;
		ans=min(ans,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}