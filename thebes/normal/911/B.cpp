#include <bits/stdc++.h>
using namespace std;

int n, a, b, i, ans;

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n-1;i++){
		int p1 = a/i;
		int p2 = b/(n-i);
		ans = max(ans,min(p1,p2));
	}
	printf("%d\n",ans);
	return 0;
}