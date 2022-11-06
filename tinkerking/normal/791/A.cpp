#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL A,B;

int main()
{
	scanf("%I64d%I64d",&A,&B);
	int ans = 0;
	while(A<=B)
	{
		ans++;
		A*=3LL;
		B*=2LL;
	}
	printf("%d\n",ans);
}