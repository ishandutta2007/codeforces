#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=1e5+5;
const ll INF=1e17;
int n,u,v,c[N],mas[N],IND,col,ans;
vector<int>g[N];
void dfs (int k, int par){
	int x=0;
	for (int i=0;i<g[k].size()&&IND==0;i++)
	if (g[k][i]!=par){
		dfs(g[k][i],k);
		if (c[k]!=c[g[k][i]])
		x=1;
	}
	if (x&&IND==0)IND=k;
}
void go (int k, int par){
	if (c[k]!=col)ans=-1;
	for (int i=0;i<g[k].size();i++)
	if (g[k][i]!=par&&g[k][i]!=IND)
	go(g[k][i],k);
}
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	if (IND==1){cout<<"YES"<<endl<<1<<endl;return 0;}
	col=c[1];
	go(1,0);
	if (ans==-1){cout<<"NO"<<endl;return 0;}
	cout<<"YES"<<endl;
	if (IND==0)IND=1;
	cout<<IND<<endl;
    return 0;
}