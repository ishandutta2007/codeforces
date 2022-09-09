#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000050;
int go[N][26],tsz,root,node[N],a[N],dp[N],tmp[N],par[N];
bool mark[N];
vector<int> pref,lzy;
void DFS(int u){
	if(mark[u]){
		pref.back()++;
		lzy.back()++;
	}
	if(par[u])dp[u]=dp[par[u]]+1;
	if(mark[u]){
		dp[u]=min(dp[u],pref.back());
	}
	tmp[u]=dp[u];
	if(mark[u])tmp[u]++;
	pref.pb(min(pref.back(),tmp[u]));
	lzy.pb(0);
	for(int i=0;i<26;i++)
		if(go[u][i]){
			DFS(go[u][i]);
			pref.pop_back();
			pref.back()+=lzy.back();
			lzy[(int)lzy.size()-2]+=lzy.back();
			lzy.pop_back();
		}
}
int main(){
	pref.pb(1e9);
	lzy.pb(0);
	int n;
	scanf("%i",&n);
	node[0]=root=++tsz;
	for(int i=1;i<=n;i++){
		int p;char c;
		scanf("%i %c",&p,&c);
		int u=node[p];
		if(!go[u][c-'a'])
			go[u][c-'a']=++tsz,
			par[tsz]=u;
		node[i]=go[u][c-'a'];
	}
	int k;
	scanf("%i",&k);
	for(int i=1;i<=k;i++)scanf("%i",&a[i]),mark[node[a[i]]]=1;
	DFS(root);
	for(int i=1;i<=k;i++)printf("%i ",dp[node[a[i]]]);
	return 0;
}