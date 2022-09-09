#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define ll long long
const int N=100050;
vector<int> E[N];
int ans[N],n,dep[N],par[N];
ll sum;
int sz[N];
void DFS(int u,int p){sz[u]=1;for(int v:E[u])if(v!=p)DFS(v,u),sz[u]+=sz[v];}
int Find(int u,int p){for(int v:E[u])if(v!=p&&sz[v]*2>n)return Find(v,u);return u;}
int Find(int u){DFS(u,0);return Find(u,0);}
vector<int> ord;
void GO(int u,int p){
	ord.pb(u);
	for(int v:E[u])if(v!=p){
		dep[v]=dep[u]+1;
		GO(v,u);
	}
}
int main(){
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	int cen=Find(1);
	GO(cen,0);
	int hal=n/2;
	for(int i=0;i<n;i++){
		ans[ord[i]]=ord[(i+hal)%n];
		sum+=2*dep[ord[i]];
	}
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++)printf("%i ",ans[i]);
	return 0;
}