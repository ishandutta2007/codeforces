#include <bits/stdc++.h>
using namespace std;

int a, b, x, p=1, N, ans, i;

int main(){
	scanf("%d%d%d",&N,&a,&b);
	for(i=3;i<=N;i++){
		scanf("%d",&x);
		if(x != a+b){
			ans = max(ans, i-p);
			p = i-1;
		}
		a = b; b = x;
	}
	ans = max(ans, N-p+1);
	printf("%d\n",ans);
	return 0;
}