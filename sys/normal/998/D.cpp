#include <bits/stdc++.h>
using namespace std;
int n,ans[15]={0,4,10,20,35,56,83,116,155,198,244,292};
int main()
{
	scanf("%d",&n);
	if(n<=11) printf("%d",ans[n]);
	else printf("%I64d",292+((long long)n-11)*49);
	return 0;
}