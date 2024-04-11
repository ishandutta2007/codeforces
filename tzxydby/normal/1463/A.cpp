#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int s=a+b+c;
		if(s%9)
		{
			puts("NO");
			continue;
		}
		int x=s/9;
		if(a<x||b<x||c<x)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}