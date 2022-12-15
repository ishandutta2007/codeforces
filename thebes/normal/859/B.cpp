#include <bits/stdc++.h>
using namespace std;

int ans = 1<<30, i, N;

int main(){
	for(scanf("%d",&N),i=1;i<=sqrt(N+0.0);i++)
		ans = min(ans, 2*((int)ceil((double)N/i)+i));
	printf("%d\n",ans);
	return 0;
}