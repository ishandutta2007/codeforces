#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+5;
int n,k,ans;
vector<int> g[maxn];
int dfs(int u,int p) {
	if (g[u].size()==1) return 1;
	vector<int> d;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (v!=p)
			d.push_back(dfs(v,u));
	}
	sort(d.begin(),d.end());
	while (d.size()>=2) {
		if (d.back()+d[d.size()-2]<=k) break;
		ans++; d.pop_back();
	}
	return d.back()+1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	for (int i=1;i<n;i++) {
		int x,y; read(x); read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (g[i].size()!=1) {
			ans=1;
			dfs(i,0);
			printf("%d\n",ans);
			return 0;
		}
	return 0;
}