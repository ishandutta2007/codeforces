#include <bits/stdc++.h>
using namespace std;

map<int,int> wtf;
long long ans; int n, m, i, x, y;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		wtf[x] = y;
	}
	for(scanf("%d",&m),i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		wtf[x] = max(wtf[x], y);
	}
	for(auto v : wtf)
		ans += v.second;
	printf("%lld\n",ans);
	return 0;
}