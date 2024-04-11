#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[300005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	if(s[1]==')'||s[n]=='(')
	{
		printf(":(\n");
		return 0;
	}
	s[1]='(',s[n]=')';
	int now=0;
	for(int i=2;i<n;i++)
	{
		if(s[i]=='(')now++;
		else if(s[i]==')')now--;
	}
	for(int i=2;i<n;i++)
	{
		if(now>=0)break;
		if(s[i]=='?')
		{
			s[i]='(';
			now++;
		}
	}
	for(int i=n-1;i>1;i--)
	{
		if(now<=0)break;
		if(s[i]=='?')
		{
			s[i]=')';
			now--;
		}
	}
	if(now!=0)
	{
		printf(":(\n");
		return 0;
	}
	int nowl=1,nowr=n;
	while(nowl<nowr)
	{
		while(nowl<=n&&s[nowl]!='?')nowl++;
		while(nowr>=1&&s[nowr]!='?')nowr--;
		if(nowl<nowr)
		{
			s[nowl]='(';
			s[nowr]=')';
		}
	}
	if(nowl==nowr)
	{
		printf(":(\n");
		return 0;
	}
	now=0;
	for(int i=2;i<n;i++)
	{
		if(s[i]=='(')now++;
		else now--;
		if(now<0)
		{
			printf(":(\n");
			return 0;
		}
	}
	printf("%s\n",s+1);
	return 0;
}