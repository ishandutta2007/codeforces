#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,lli>;

int n;
vector<int> adj[1001];

int getcnt(int cur,int p) {
	int cnt=1;
	for(auto &it:adj[cur])if(it!=p)  {
		cnt += getcnt(it,cur);
	}
	return cnt;
}
pii find_leaf(int cur,int p) {
	pii val(0,0);
	if(sz(adj[cur])==1) {
		val.fi = cur;
	}
	for(auto &it:adj[cur]) if(it!=p)  {
		pii tmp = find_leaf(it,cur);
		if(tmp.fi) {
			if(!val.fi) val.fi=tmp.fi;
			else if(!val.se) val.se=tmp.fi;
		}
		if(tmp.se) {
			if(!val.fi) val.fi=tmp.se;
			else if(!val.se) val.se=tmp.se;
		}
	}
	return val;
}

void cut(int cur,int p,int tar) {
	if(cur==tar) {
		for(int i=0;i<sz(adj[cur]);i++) if(adj[cur][i]==p) {
			adj[cur].erase(adj[cur].begin()+i);
			break;
		}
		return;
	}
	for(auto &it:adj[cur]) if(it!=p) cut(it,cur,tar);
}

int main() {
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int root=1, sz=n;
	while(sz>1) {	
		int u,v;
		tie(u,v) = find_leaf(root, 0);
		printf("? %d %d\n", u,v);
		fflush(stdout);
		
		scanf("%d",&root);
		if(root==u || root==v) {
			printf("! %d\n",root);
			fflush(stdout);
			return 0;
		}

		cut(u,0,root);
		cut(v,0,root);
		sz = getcnt(root, 0);
	}
	printf("! %d\n",root);
	return 0;
	
	return 0;
}