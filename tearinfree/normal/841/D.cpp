#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <map>
#include <set>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

int n,m;
int d[300001],used[300001];
vector<ip> arr[300001],adj[300001];
bool vis[300001];
vector<int> res;

void make_tree(int node) {
	vis[node]=true;
	for(auto &it:arr[node]) {
		if(!vis[it.first]) {
			adj[node].push_back(ip(it.first,it.second));
			adj[it.first].push_back(ip(node,it.second));
			make_tree(it.first);
		}
	}
}
void DFS(int node,int p) {
	int cnt=0;
	for(auto &it:adj[node]) {
		if(it.first==p) continue;
		DFS(it.first,node);
		if(used[it.first]) {
			cnt++;
			res.push_back(it.second);
		}
	}
	if(d[node]==0) {
		if(cnt&1) used[node]=1;
		else used[node]=0;
	}
	else {
		if(cnt&1) used[node]=0;
		else used[node]=1;
	}
}

int main() {
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",d+i);
	for(int i=0;i<m;i++) {
		scanf("%d%d",&u,&v);
		arr[u].push_back(ip(v,i+1));
		arr[v].push_back(ip(u,i+1));
	}
	
	bool flag=false;
	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(d[i]==-1) flag=true;
		else cnt+=d[i];
	}
	if(cnt&1) {
		if(!flag) {
			puts("-1");
			return 0;
		}
		for(int i=1;i<=n;i++) {
			if(d[i]==-1) {
				d[i]=1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++) if(d[i]==-1) d[i]=0;
	make_tree(1);
	DFS(1,0);
	
	sort(res.begin(),res.end());
	int s=res.size();
	printf("%d\n",s);
	for(auto &it:res) printf("%d\n",it);

	return 0;
}