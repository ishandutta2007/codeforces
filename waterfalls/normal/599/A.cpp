#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main() {
	scanf("%d%d%d",&a,&b,&c);
	int ans = 1e9;
	ans = min(ans,a+b+c);
	ans = min(ans,a+c+c+a);
	ans = min(ans,b+c+c+b);
	ans = min(ans,a+b+b+a);
	printf("%d\n",ans);

	return 0;
}