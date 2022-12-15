#include <bits/stdc++.h>
using namespace std;

int N, i, x, a, b, ans;

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		scanf("%d",&x);
		if(x==1) a++;
		else b++;
	}
	ans += min(a,b); 
	x = min(a,b);
	a -= x; b -= x;
	ans += a/3;
	printf("%d\n",ans);
	return 0;
}