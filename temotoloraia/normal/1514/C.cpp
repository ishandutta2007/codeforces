#include <bits/stdc++.h>
using namespace std;
bool ok[100005];
int main()
{
	int n;
	scanf("%d",&n);
	long long prod=1;
	for (int i=1;i<n;i++)
	{
		if (__gcd(n,i)==1)
		{
			ok[i]=1;
			prod=(prod*i)%n;
		}
	}
	if (prod != 1 && prod !=n-1)
	    assert (0);
	if (prod!=1)
	ok[prod]=0;
	printf("%d\n",count(ok+1,ok+n,1));
	for (int i=1;i<n;i++)
	{
		if (ok[i])
		printf("%d ",i);
	}
}