#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, m, p, i, x, arr[MN], cnt;
vector<int> vec[MN], ans;
map<int,int> mp, res;
inline void inc(int v){
	if(mp[v]==res[v]) cnt--;
	if((++mp[v])==res[v]) cnt++;
}
inline void dec(int v){
	if(mp[v]==res[v]) cnt--;
	if((--mp[v])==res[v]) cnt++;
}
int main(){
	for(scanf("%d%d%d",&n,&m,&p),i=1;i<=n;i++){
		scanf("%d",&x);
		vec[(i-1)%p].push_back(x);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&arr[i]);
		res[arr[i]]++;
	}
	int sz = res.size();
	for(int j=0;j<p;j++){
		mp.clear(); cnt=0;
		if(vec[j].size()<m) continue;
		for(i=0;i<m;i++) inc(vec[j][i]);
		if(cnt==sz) ans.push_back((i-m)*p+j);
		for(;i<vec[j].size();i++){
			dec(vec[j][i-m]); inc(vec[j][i]);
			if(cnt==sz)
				ans.push_back((i-m+1)*p+j);
		}
	}
	printf("%d\n",ans.size());
	sort(ans.begin(),ans.end());
	for(auto v : ans) printf("%d ",v+1);
	return 0;
}