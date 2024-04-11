#include <bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,m;
vector<vector<long long>>ls;
vector<long long>rs,vis;
long long dfs(long long v) {
	if(vis[v])return 0;
	vis[v]=1;
	for(auto &to:ls[v]){
		if(rs[to]==-1){
			rs[to]=v;
			return 1;
		}
	}
	for(auto &to:ls[v]){
		if(dfs(rs[to])){
			rs[to]=v;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%lld%lld",&n,&m);
	vector<long long>l,r;
	for(long long i=1;i<=n;i++){
		long long x;
		scanf("%lld",&x);
		if(3*x>m)l.push_back(x);
		else r.push_back(x);
	}
	ls.resize(l.size());
	rs.resize(r.size(),-1);
	for(long long i=0;i<(long long)l.size();i++){
		for(long long o=0;o<(long long)r.size();o++){
			if(l[i]%r[o]==0&&2*l[i]+r[o]<=m){
				ls[i].push_back(o);
			}
		}
	}
	long long cnt=0;
	for(long long i=0;i<(long long)l.size();i++){
		vis.assign(l.size(),0);
		cnt+=dfs(i);
	}
	if(cnt<(long long)l.size())return puts("-1"),0;
	vector<pair<long long,long long>>ans;
	for(long long o=0;o<(long long)r.size();o++){
		if(rs[o]==-1)ans.push_back({3*r[o],2*r[o]});
		else ans.push_back({2*l[rs[o]]+r[o],l[rs[o]]+r[o]});
	}
	printf("%lld\n",(long long)ans.size());
	for(auto it:ans)printf("%lld %lld\n",it.first,it.second);
	return 0;
}