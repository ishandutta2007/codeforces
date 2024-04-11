#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[500005];
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int pos1=0,pos2=0;
	for(int i=1;i<=n;i++)
	{
		if(s[pos1]=='['&&s[i]==':')pos1=i;
		else if(s[pos1]!='['&&s[pos1]!=':'&&s[i]=='[')pos1=i;
	}
	for(int i=n;i>=1;i--)
	{
		if(s[pos2]==']'&&s[i]==':')pos2=i;
		else if(s[pos2]!=']'&&s[pos2]!=':'&&s[i]==']')pos2=i;
	}
	if(s[pos1]!=':'||s[pos2]!=':'||pos1>=pos2)
	{
		printf("-1\n");
		return 0;
	}
	int ans=4;
	for(int i=pos1+1;i<pos2;i++)
	  if(s[i]=='|')ans++;
	printf("%d\n",ans);
	return 0;
}