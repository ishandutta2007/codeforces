#include <bits/stdc++.h>
using namespace std;
int n,dp[70];
int main()
{
	scanf("%d",&n);
	if(n%2)
	{
		printf("0");
		return 0;
	}
	printf("%d",(int)pow(2,n/2));
	return 0;
}