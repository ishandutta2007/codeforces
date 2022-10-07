#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=(int)strlen(s+1);
		bool flag=1;
		for(int i=2;i<=n;i++)
		{
			if(s[i]!=s[i-1])
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("%s\n",s+1);
		else
		{
			for(int i=1;i<=n;i++)printf("01");
			printf("\n");
		}
	}
	return 0;
}