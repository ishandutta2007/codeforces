#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> adj[100001];
double res=0;
int cnt=0;

void DFS(int node,int p,int l,double r) {
	if(node!=1&&adj[node].size()==1) {
		res+=l*r;
		return;
	}

	int c=adj[node].size()-1;
	if(node==1)c++;
	for(auto &it:adj[node]) {
		if(it==p) continue;
		DFS(it,node,l+1,r/c);
	}
}

int main() {
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1,0,0,1.0);
	printf("%.10lf\n",res);
	return 0;
}