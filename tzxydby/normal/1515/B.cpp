#include<bits/stdc++.h>
using namespace std;
int ok(int n)
{
	int x=sqrt(n)+0.5;
	if(x*x==n)
		return 1;
	else
		return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if((n%2==0)&&ok(n/2))
			puts("YES");
		else if((n%4==0)&&ok(n/4))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}