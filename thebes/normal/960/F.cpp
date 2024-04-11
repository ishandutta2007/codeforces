#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
map<int,int> mp[MN];
int N, M, i, x, y, w, len, ans;

int getedge(int n,int w){
	auto it=mp[n].lower_bound(w);
	if(it==mp[n].begin()) return 1;
	if((--it)==mp[n].end()) return 1;
	else return it->second+1;
}

int main(){
	for(scanf("%d%d",&N,&M);M;M--){
		scanf("%d%d%d",&x,&y,&w);
		len = getedge(x, w);
		if(getedge(y,w+1)>len) continue;
		ans = max(ans, len);
		mp[y][w]=max(mp[y][w],len);
		auto it=mp[y].upper_bound(w);
		for(;it!=mp[y].end()&&it->second<=len;)
		{auto it2=it;it++;mp[y].erase(it2);}
	}
	printf("%d\n",ans);
	return 0;
}