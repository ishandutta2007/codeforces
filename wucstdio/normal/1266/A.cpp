#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
char s[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=(int)strlen(s+1);
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			  flag=1;
		}
		if(!flag)
		{
			printf("cyan\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				s[i]='3';
				break;
			}
		}
		flag=0;
		for(int i=1;i<=n;i++)
		{
			if((s[i]-'0')%2==0)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			printf("cyan\n");
			continue;
		}
		int num=0;
		for(int i=1;i<=n;i++)num+=s[i]-'0';
		if(num%3==0)printf("red\n");
		else printf("cyan\n");
	}
	return 0;
}