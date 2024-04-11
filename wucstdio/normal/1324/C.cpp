#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[200005];
int st[200005],top;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=(int)strlen(s+1);
		top=1;
		st[top]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R')st[++top]=i;
		}
		st[++top]=n+1;
		int ans=0;
		for(int i=2;i<=top;i++)ans=max(ans,st[i]-st[i-1]);
		printf("%d\n",ans);
	}
	return 0;
}