#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,s,k,x[1005];
bool flag;
void check(int pos)
{
	for(int i=1;i<=k;i++)
	  if(x[i]==pos)return;
	flag=1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d%d%d",&n,&s,&k);
		for(int i=1;i<=k;i++)scanf("%d",&x[i]);
		for(int d=0;d<=n;d++)
		{
			if(s-d>=1)check(s-d);
			if(s+d<=n)check(s+d);
			if(flag)
			{
				printf("%d\n",d);
				break;
			}
		}
	}
	return 0;
}