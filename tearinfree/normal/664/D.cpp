#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int,int> ip;
int n,m,vis[100001];
vector<ip> adj[100001];
vector<int> res;

bool dfs(int cur,int &cnt,int ce,int vn,bool trace) {
	vis[cur]=vn;
	if(vn) cnt++;
	for(auto &it:adj[cur]) {
		if(vis[it.second]==-1) {
			if(!dfs(it.second,cnt,ce,vn^it.first^ce,trace)) {
				return false;
			}
		}
		else{ 
			if(vn^vis[it.second]^it.first!=ce) {
				return false;
			}
		}
	}
	if(trace && vn) {
		res.push_back(cur);
	}
	return true;
}
void clear(int cur) {
	vis[cur]=-1;
	for(auto &it:adj[cur]) {
		if(vis[it.second]==-1) continue;
		clear(it.second);
	}
}
int Check(int a,int b) {
	int cnt=0;
	fill(vis,vis+n+1,-1);
	for(int i=1;i<=n;i++) if(vis[i]==-1) {
		if(!dfs(i,cnt,a,b,false)) {
			return -1;
		}
	}
	return cnt;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b;
		char c;
		scanf("%d%d %c",&a,&b,&c);
		if(c=='R') c=0;
		else c=1;
		adj[a].push_back(ip(c,b));
		adj[b].push_back(ip(c,a));
	}

	vector<int> cj,rj;
	int mx=n+1,c,ii,jj;
	for(int i=0;i<2;i++) {
		fill(vis,vis+n+1,-1);
		c=0;
		cj.clear();
		for(int k=1;k<=n;k++) {
			if(vis[k]==-1) {
				int c1=0,c2=0;
				bool f1,f2;
				f1=dfs(k,c1,i,0,false);
				clear(k);
				f2=dfs(k,c2,i,1,false);
				
				if(!f1 && !f2) c=-1;
				else if(!f1) c+=c2,cj.push_back(1);
				else if(!f2) c+=c1,cj.push_back(0);
				else {
					if(c1<c2) c+=c1,cj.push_back(0);
					else c+=c2,cj.push_back(1);
				}
			}
			if(c==-1) break;
		}
		if(c!=-1 && mx>c) {
			mx=c;
			ii=i;
			rj=cj;
		}
	}
	if(mx==n+1) {
		puts("-1");
		return 0;
	}
	int t=0;
	fill(vis,vis+n+1,-1);
	for(int i=1;i<=n;i++) if(vis[i]==-1) {
		dfs(i,c,ii,rj[t++],true);
	}

	printf("%d\n",mx);
	sort(res.begin(),res.end());
	for(auto &it:res)
		printf("%d ",it);

	return 0;
}