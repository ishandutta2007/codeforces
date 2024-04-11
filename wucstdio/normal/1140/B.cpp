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
		int ans=100000,num=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='<')num++;
			else break;
		}
		ans=min(ans,num);
		num=0;
		for(int i=n;i>=1;i--)
		{
			if(s[i]=='>')num++;
			else break;
		}
		ans=min(ans,num);
		printf("%d\n",ans);
	}
	return 0;
}