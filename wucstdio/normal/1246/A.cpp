#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,p;
int calc(int x)
{
	int ans=0;
	while(x)
	{
		if(x&1)ans++;
		x>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=0;i<=1000;i++)
	{
		if(n<=0)break;
		if(n<i)break;
		if(calc(n)<=i)
		{
			printf("%d\n",i);
			return 0;
		}
		n-=p;
	}
	printf("-1\n");
	return 0;
}