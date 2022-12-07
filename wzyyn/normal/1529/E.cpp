#include<bits/stdc++.h>
using namespace std;

const int N=300005;
int n,ans;
vector<int> e1[N],e2[N];
int dfn[N],ed[N],pos[N];
set<int> S;

void dfs(int x){
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	for (auto i:e1[x])
		dfs(i);
	ed[x]=*dfn;
}
void solve(int x,int v){
	int dp=-1,ip=-1;
	auto it=S.lower_bound(dfn[x]);
	if (it==S.end()||*it>ed[x]){
		ip=x; ++v;
		S.insert(dfn[x]);
		auto it=S.lower_bound(dfn[x]);
		if (it!=S.begin()){
			int y=pos[*(--it)];
			if (dfn[y]<=dfn[x]&&ed[x]<=ed[y]){
				dp=y; --v;
				S.erase(dfn[y]);
			}
		}
	}
	
	ans=max(ans,v);
	for (auto i:e2[x])
		solve(i,v);
	if (dp) S.insert(dfn[dp]);
	if (ip) S.erase(dfn[ip]);
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) e1[i].resize(0);
	for (int i=1;i<=n;i++) e2[i].resize(0);
	for (int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		e2[x].push_back(i);
	}
	for (int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		e1[x].push_back(i);
	}
	S.clear();
	*dfn=ans=0;
	dfs(1);
	solve(1,0);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}