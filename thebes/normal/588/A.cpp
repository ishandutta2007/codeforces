#include <bits/stdc++.h>
using namespace std;

int opt=1<<30, N, i, x, y, ans;

int main(){
	for(scanf("%d",&N);i<N;i++){
		scanf("%d%d",&x,&y);
		opt = min(opt, y);
		ans += x*opt;
	}
	printf("%d\n",ans);
	return 0;
}