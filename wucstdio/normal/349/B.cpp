#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,v[15],minn=1,num,rest;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<10;i++)
	{
		scanf("%d",&v[i]);
		if(v[i]<=v[minn])minn=i;
	}
	num=n/v[minn];
	rest=n%v[minn];
	if(num==0)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=9;i>=minn;i--)v[i]-=v[minn];
	while(rest!=0&&num!=0)
	{
		bool flag=0;
		for(int i=9;i>=minn;i--)
		{
			if(v[i]<=rest)
			{
				printf("%d",i);
				rest-=v[i];
				num--;
				flag=1;
				break;
			}
		}
		if(flag==0)break;
	}
	for(int i=1;i<=num;i++)printf("%d",minn);
	printf("\n");
	return 0;
}