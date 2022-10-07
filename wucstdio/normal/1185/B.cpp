#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,m;
char s[1000005],t[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s+1,t+1);
		n=(int)strlen(s+1);
		m=(int)strlen(t+1);
		int now=1;
		bool flag=1;
		for(int i=1;i<=m;i++)
		{
			if(t[i]==t[i-1])continue;
			if(t[i]!=s[now])
			{
				flag=0;
				break;
			}
			int num1=0,num2=0;
			int st=now;
			while(s[now]==s[st])
			{
				now++;
				num1++;
			}
			st=i;
			while(t[st]==t[i])
			{
				st++;
				num2++;
			}
			if(num1>num2)
			{
				flag=0;
				break;
			}
		}
		if(now!=n+1)flag=0;
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}