#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k,a[200001];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int now=k,sum=0;
	for(int i=n;i>=1;i--)
	{
		a:
		if(now>=a[i])
		{
			now-=a[i];
			sum++;
		}
		else
		{
			m--;
			if(!m)
			{
				printf("%d",sum);
				return 0;
			}
			now=k;
			goto a;
		}
	}
	printf("%d",sum);
	return 0;
}
//