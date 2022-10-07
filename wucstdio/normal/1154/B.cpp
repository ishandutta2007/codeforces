#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num1,num2,num3;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int v;
		scanf("%d",&v);
		if(!num1||num1==v)num1=v;
		else if(!num2||num2==v)num2=v;
		else if(!num3||num3==v)num3=v;
		else
		{
			printf("-1\n");
			return 0;
		}
	}
	if(!num2&&!num3)
	{
		printf("0\n");
		return 0;
	}
	else if(!num3)
	{
		if(num1>num2)swap(num1,num2);
		printf("%d\n",((num2-num1)&1)?num2-num1:(num2-num1)>>1);
		return 0;
	}
	if(num1>num2)swap(num1,num2);
	if(num2>num3)swap(num2,num3);
	if(num1>num2)swap(num1,num2);
	if(2*num2==num1+num3)printf("%d\n",num2-num1);
	else printf("-1\n");
	return 0;
}