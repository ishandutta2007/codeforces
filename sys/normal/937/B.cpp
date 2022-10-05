#include <bits/stdc++.h>
using namespace std;
int p,y;
bool is_prime(int n)
{
	for(int i=2;i<=min((int)sqrt(n),p);i++)
		if(n/(double)i==n/i)
			return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&p,&y);
	for(int i=y;i>p;i--)
	{
		if(is_prime(i)){printf("%d",i); return 0;}
	}
	printf("-1");
	return 0;
}