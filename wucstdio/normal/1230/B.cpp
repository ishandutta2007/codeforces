#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200005];
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	if(k==0)
	{
		printf("%s\n",s+1);
		return 0;
	}
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!k)break;
		if(i==1&&s[i]!='1')
		{
			s[i]='1';
			k--;
			continue;
		}
		if(i!=1&&s[i]!='0')
		{
			s[i]='0';
			k--;
			continue;
		}
	}
	printf("%s\n",s+1);
	return 0;
}