#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e5+7;
vector<int> e[maxn];
int color[maxn],groupid[maxn],dfn[maxn],low[maxn],cntuni[maxn];
int sz;
int S[maxn];
int n,m,timestamp,groupstamp;;
char s[maxn];
void tarjan(int u){
	color[u]=1;
	S[++sz]=u;
	timestamp++;
	dfn[u]=low[u]=timestamp;
	for(auto v:e[u]){
		if(!color[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else{
			if(color[v]==1){
				low[u]=min(low[u],dfn[v]);
			}
		}
	}
	if(low[u]>=dfn[u]){
		int v;
		static vector<int> c;
		c.clear();
		groupstamp++;
		do{
			v = S[sz];
			sz--;
			groupid[v]=groupstamp;
			color[v]=2;
			c.pb(v);
		}while(v!=u);
		cntuni[groupstamp]=0;
		int largest_A=-1,least_E=100000000;
		for (auto v:c)
			if(s[abs(v-n)]=='A'){
				cntuni[groupstamp]++;
				largest_A=max(largest_A, abs(v-n));
			}else{
				least_E=min(least_E,abs(v-n));
			}
		if(least_E<=largest_A){
			throw "existential to universal";
		}
		if(cntuni[groupstamp]>=2){
			throw "more than two universal variables in a SCC";
		}
		int flag=0;
		for (auto v:c){
			for (auto vv:e[v]){
				if (groupid[v]!=groupid[vv]){
					flag=flag+cntuni[groupid[vv]];
				}
			}
		}
		if(cntuni[groupstamp]&&flag){
			throw "universal to universal";
		}
		cntuni[groupstamp]+=flag;
	}
}
int main(int argc,char **argv){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		for (int i=-n;i<=n;i++){
			e[n+i].clear();
		}
		for (int sth=1,u,v;sth<=m;sth++){
			scanf("%d%d",&u,&v);
			e[n-u].pb(n+v);
			e[n-v].pb(n+u);
		}
		try{
			timestamp=groupstamp=0;
			for(int i=-n;i<=n;i++){
				color[n+i]=0;
			}
			for(int i=-n;i<=n;i++){
				if(i!=0&&!color[n+i]){
					tarjan(n+i);
				}
			}
			for(int i=1;i<=n;i++){
				if (groupid[n+i]==groupid[n-i]){
					throw "Failed on 2-SAT";
				}
			}
		}
		catch(const char *s){
			printf("FALSE\n");
			continue;
		}
		printf("TRUE\n");
	}
	return 0;
}