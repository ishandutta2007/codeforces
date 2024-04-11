#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,c,d,sum,k=1;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	sum=a+b+c+d;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a+b+c+d>sum)
			k++;
	}
	printf("%d\n",k);
	return 0;
}