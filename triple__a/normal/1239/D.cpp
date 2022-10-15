#include<bits/stdc++.h>
using namespace std;

const int maxn=2000007;
int q,n,m;
vector<int> g[maxn];
int dfn[maxn],low[maxn],color[maxn],ans,dfsClock,sccCnt;
bool ins[maxn];

stack<int> stk;

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) {
        if (!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
        else if (ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++sccCnt;
        do {
            color[u] = sccCnt;
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

int main(){
	scanf("%d",&q);
	while (q--){
		scanf("%d%d",&n,&m);
		dfsClock=sccCnt=0;	
		for (int i=1;i<=2*n;++i){
			g[i].clear();
			dfn[i]=low[i]=ins[i]=0;
			color[i]=2*n+1;
		}
		while (!stk.empty()){
			stk.pop();
		}
		while (m--){
			int u,v;
			scanf("%d%d",&u,&v);
			if (u==v) continue;
			g[u].push_back(v);
			g[v+n].push_back(u+n);
		}
		tarjan(1);
		int ans=0;
		vector<int> fk[2];
		fk[0].clear(),fk[1].clear();
		for (int i=1;i<=n;++i){
			if (color[i]==1){
				ans++;
				fk[0].push_back(i);
			}
			if (color[i+n]==1){
				ans--;
				fk[1].push_back(i);
			}
		}
		if (ans==n||ans==-n){
			printf("No\n");
			continue;
		}
		for (int i=1;i<=n;++i){
			if (color[i]!=1&&color[i+n]!=1){
				if (fk[0].size()){
					fk[1].push_back(i);
				}
				else{
					fk[0].push_back(i);
				}
			}
		}
		printf("Yes\n%d %d\n",fk[0].size(),fk[1].size());
		for (auto c:fk[0]){
			printf("%d\n",c);
		}
		for (auto c:fk[1]){
			printf("%d\n",c);
		}
	}
	return 0;
}