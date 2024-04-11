#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q;
bool check(int n)
{
	while(n)
	{
		if(!(n&1))return 1;
		n>>=1;
	}
	return 0;
}
int work(int n)
{
	int ans=1;
	while(n)n>>=1,ans<<=1;
	return ans-1;
}
int calc(int n)
{
	int ans=0;
	while(n)n>>=1,ans++;
	return ans;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		if(check(n))printf("%d\n",work(n));
		else
		{
			bool flag=1;
			for(int i=2;i*i<=n;i++)
			{
				if(n%i==0)
				{
					printf("%d\n",n/i);
					flag=0;
					break;
				}
			}
			if(flag)printf("1\n");
		}
	}
	return 0;
}