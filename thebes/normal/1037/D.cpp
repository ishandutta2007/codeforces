#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, i, j, p[MN], x, y, arr[MN];
vector<int> adj[MN];
set<int> s; queue<int> q;

bool solve(){
	if(arr[1]!=1) return 0;
	q.push(1); j=2;
	while(q.size()){
		int c = q.front(), sz=0; q.pop();
		for(auto v : adj[c]){
			if(v == p[c]) continue;
			s.insert(v); sz++; p[v]=c;
		}
		for(int k=0;k<sz;k++)
			s.erase(arr[j+k]);
		if(s.size()) return 0;
		for(int k=0;k<sz;k++)
			q.push(arr[j+k]);
		j += sz;
	}
	return 1;
}

int main(){
	for(scanf("%d",&n),i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=n;i++) scanf("%d",&arr[i]);
	printf("%s\n",solve()?"Yes":"No");
	return 0;
}