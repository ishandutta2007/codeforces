#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(a+b<=n-2||(a==n&&b==n))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}