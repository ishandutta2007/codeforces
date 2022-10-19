#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,sum1=0,sum2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum1+=x;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum2+=x;
	}
	if(sum1>=sum2)
		puts("Yes");
	else
		puts("No");
	return 0;
}