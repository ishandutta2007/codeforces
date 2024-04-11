#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005],t[100005];
int n,m;
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]!='a')
		  t[++m]=s[i];
	}
	if(m&1)
	{
		printf(":(\n");
		return 0;
	}
	for(int i=1;i<=m/2;i++)
	{
		if(t[i]!=t[m/2+i])
		{
			printf(":(\n");
			return 0;
		}
	}
	for(int i=1;i<=m/2;i++)
	{
		if(s[n-i+1]=='a')
		{
			printf(":(\n");
			return 0;
		}
	}
	for(int i=1;i<=n-m/2;i++)
	  putchar(s[i]);
	putchar('\n');
	return 0;
}