#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;

int n,m,cnt=0;
vector<int> mp[maxn];
bool vis[maxn],ck[maxn];
int ans[maxn];
stack<int > q;

int main(){
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
	}
	for (int i=1;i<=n;++i){
		if (!vis[i]){
			vis[i]=1;
			q.push(i);
			for (int j=0;j<mp[i].size();++j){
				if (!vis[mp[i][j]]){
					vis[mp[i][j]]=1;
				}
			}
		}
	}
	memset(vis,0,sizeof(vis));
	memset(ck,0,sizeof(ck));
	while(!q.empty()){
		int u=q.top();
		bool fg=1-ck[u];
		for (int j=0;j<mp[u].size();++j){
			if (vis[mp[u][j]]){
				fg=0;
				break;
			}
		}
		if (fg){
			ans[++cnt]=u;
			vis[u]=1;
			for (int j=0;j<mp[u].size();++j){
				ck[mp[u][j]]=1;
			}
		}
		q.pop();
	} 
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}