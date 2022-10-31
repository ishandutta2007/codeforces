#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;

int n;
vector<int> adj[200001];

lli sum=0;
int co[200001],sz[200001],mx,id,dist[200001][2],tid;
pii od[200001];

struct data{
	int a,b,c;
	data(int a,int b,int c)
	:a(a),b(b),c(c) {}
};
vector<data> res;

int dfs(int cur,int p) {
	int &m1=dist[cur][0],&m2=dist[cur][1];
	for(auto &it:adj[cur]) {
		if(it==p) continue;

		int val=dfs(it,cur);
		if(val > m1) {
			m2=m1; m1=val;
		}
		else if(val > m2) {
			m2=val;
		}
	}
	return m1+1;
}
void getlen(int cur,int p,int d) {
	int m1=d,m2=dist[cur][0],m3=dist[cur][1];
	if(m1<m2) swap(m1,m2);
	if(m2<m3) swap(m2,m3);
	if(m1+m2>=mx) {
		mx=m1+m2; id=cur;
	}
	for(auto &it:adj[cur]) {
		if(it==p) continue;
		if(dist[it][0] == m1-1) getlen(it,cur,m2+1);
		else getlen(it,cur,m1+1);
	}
}
int color(int cur,int p,int len) {
	if(len==mx) {
		od[cur]=pii(mx,id);
		co[cur]=1;
		tid=cur;
		return 1;
	}
	for(auto &it:adj[cur]) {
		if(it==p) continue;

		int val = color(it,cur,len+1);
		if(val) {
			od[cur] = max( pii(len,id), pii(mx-len,tid) );
			co[cur]=1;
			return 1;
		}
	}
	return 0;
}
int find(int cur,int p,int d,int t) {
	int s=1;
	sum += d;
	for(auto &it:adj[cur]) {
		if(it==p) continue;
		s+=find(it,cur,d+1,t);
	}
	res.push_back(data(cur,t,cur));
	return s;
}
void getrem(int cur,int p,int len) {
	if(len == 0) return;
	sum+=len;
	res.push_back(data(cur,tid,cur));
	for(auto &it:adj[cur]) {
		if(it==p) continue;
		if(co[it]) {
			getrem(it,cur,len-1);
			return;
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
		
	dfs(1,0);
	getlen(1,0,0);
	color(id,0,0);
	for(int i=1;i<=n;i++) {
		if(co[i]) {
			for(auto &it:adj[i]) {
				if(!co[it]) {
					int s=find(it,i,1,od[i].second);
					sum += 1ll*s*od[i].first;
				}
			}
		}
	}
	getrem(id,0,mx);

	printf("%lld\n",sum);
	for(auto &it:res) printf("%d %d %d\n",it.a,it.b,it.c);

	return 0;
}