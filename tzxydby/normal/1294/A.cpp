#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,b,c,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&n);
		int k=(n+a+b+c)/3;
		if((n+a+b+c)%3||a>k||b>k||c>k)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}