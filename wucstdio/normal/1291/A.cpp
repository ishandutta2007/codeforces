#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int num=0;
		for(int i=1;i<=n;i++)
		  if((s[i]-'0')&1)num++;
		if(num<2)
		{
			puts("-1");
			continue;
		}
		num=2;
		for(int i=1;i<=n;i++)
		{
			if((s[i]-'0')&1)
			{
				putchar(s[i]);
				num--;
				if(num==0)break;
			}
		}
		puts("");
	}
	return 0;
}