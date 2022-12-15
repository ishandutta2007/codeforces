#include <bits/stdc++.h>
using namespace std;
int cnt[1005];
int main(){
	int N, i, x, ans=0;
	for(scanf("%d",&N),i=1;i<=N;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&x);
			if(x) cnt[i]++;
		}
		if(cnt[i]>=2) ans++;
	}
	printf("%d\n",ans);
	return 0;
}