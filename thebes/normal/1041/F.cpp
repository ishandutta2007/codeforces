#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int a[MN], b[MN], n, m, i, x, y, lol=1, ans;
map<int,int> mp;

int main(){
	for(scanf("%d%d",&n,&a[0]),i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(scanf("%d%d",&m,&b[0]),i=1;i<=m;i++)
		scanf("%d",&b[i]);
	while(lol<1e9){
		mp.clear();
		for(i=1;i<=n;i++)
			mp[a[i]%(2*lol)]++;
		for(i=1;i<=m;i++)
			mp[(b[i]%(2*lol)+lol)%(2*lol)]++;
		for(auto v : mp)
			ans = max(ans, v.second);
		lol *= 2;
	}
	mp.clear();
	for(i=1;i<=n;i++)
		mp[a[i]]++;
	for(i=1;i<=m;i++)
		mp[b[i]]++;
	for(auto v : mp)
		ans = max(ans, v.second);
	printf("%d\n",ans);
	return 0;
}