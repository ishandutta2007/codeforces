#include <bits/stdc++.h>
using namespace std;

int x, ans=-(1<<30), N, i;

int main(){
	for(scanf("%d",&N);i<N;i++){
		scanf("%d",&x);
		if(x<0) ans=max(ans,x);
		else{
			int y=floor(sqrt(x+0.0));
			if(x!=y*y) ans=max(ans,x);
		}
	}
	printf("%d\n",ans);
	return 0;
}