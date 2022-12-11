#include <queue>
#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<int,int> mp[100005];
int main(){
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=n,u,v,w; --i; mp[u][v]=mp[v][u]=w)
		scanf("%d%d%d",&u,&v,&w);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i=1; i<=n; ++i)
		if(mp[i].size()==1)
			pq.push(make_pair(mp[i].begin()->second,i));
	for(int rem=n,d,u; rem-->k||pq.size()>2; ){
		d=pq.top().first,u=pq.top().second;
		pq.pop();
		ans=max(ans,d);
		int i=mp[u].begin()->first;
		mp[i].erase(u);
		mp[u].erase(i);
		if(mp[i].size()==1)
			pq.push(make_pair(d+mp[i].begin()->second,i));
	}
	printf("%d\n",ans);
	return 0;
}