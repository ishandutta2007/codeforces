#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		if(!(n%10)) n/=10;
		else n--;
	}
	printf("%d",n);
	return 0;
}