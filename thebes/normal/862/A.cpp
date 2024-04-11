#include <bits/stdc++.h>
using namespace std;

int cnt[101], n, k, i, x, ans;

int main(){
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++){
		scanf("%d",&x);
		cnt[x]++;
	}
	for(i=0;i<k;i++)
		if(!cnt[i]) ans++;
	ans += cnt[k];
	printf("%d\n",ans);
	return 0;
}