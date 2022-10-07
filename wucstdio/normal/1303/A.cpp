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
		scanf("%s",s+1);
		n=strlen(s+1);
		int minn=n+1,maxx=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				cnt++;
				minn=min(minn,i);
				maxx=max(maxx,i);
			}
		}
		if(minn>maxx)printf("0\n");
		else printf("%d\n",maxx-minn-cnt+1);
	}
	return 0;
}