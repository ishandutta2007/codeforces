#include<bits/stdc++.h>
#define N 200005

int T;

int n,a[N];

int cnt[N];

std::vector<int> E[N];

int tmp;
bool flg;
int dfn[N],low[N],_dfn;
bool vis[N];
std::stack<int> st;
inline void dfs(int u){
	low[u]=dfn[u]=++_dfn;
	st.push(u),vis[u]=1;
	for(auto v:E[u]) if(v!=tmp){
		if(!dfn[v])
			dfs(v),low[u]=std::min(low[u],low[v]);
		else if(vis[v])
			low[u]=std::min(low[u],dfn[v]);
		if(u==v)
			flg=0;
	}
	if(dfn[u]==low[u]){
		int sz=0;
		while(st.size()){
			int x=st.top();
			st.pop();
			vis[x]=0;
			sz++;
			if(x==u)
				break;
		}
		if(sz>1)
			flg=0;
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			cnt[i]=0,E[i].clear();
		int mx=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			if(cnt[a[i]]>mx)
				tmp=a[i],mx=cnt[a[i]];
		}
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			E[a[i]].push_back(x);
		}
		_dfn=0;
		for(int i=1;i<=n;i++)
			dfn[i]=0;
		flg=1;
		for(int i=1;i<=n;i++)
			if(i!=tmp&&!dfn[i])
				dfs(i);
		puts(flg?"AC":"WA");
	}
}