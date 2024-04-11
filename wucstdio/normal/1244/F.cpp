#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,d1[200005],d2[200005];
char s[200005];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		if(s[(i+n-2)%n+1]==s[i]||s[i]==s[i%n+1])
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		if(k&1)
		{
			for(int i=1;i<=n;i++)
			  s[i]=(s[i]=='W')?'B':'W';
		}
		printf("%s\n",s+1);
		return 0;
	}
	int st=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==s[i%n+1])
		{
			st=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[(st+i-1)%n+1]==s[(st+i-2)%n+1])d1[(st+i-1)%n+1]=0;
		else if(s[(st+i-1)%n+1]==s[(st+i)%n+1])d1[(st+i-1)%n+1]=0;
		else d1[(st+i-1)%n+1]=d1[(st+i-2)%n+1]+1;
	}
	for(int i=n;i>=1;i--)
	{
		if(s[(st+i-1)%n+1]==s[(st+i)%n+1])d2[(st+i-1)%n+1]=0;
		else if(s[(st+i-1)%n+1]==s[(st+i-2)%n+1])d2[(st+i-1)%n+1]=0;
		else d2[(st+i-1)%n+1]=d2[(st+i)%n+1]+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(k<d1[i]&&k<d2[i])
		{
			if(k&1)putchar(s[i]=='W'?'B':'W');
			else putchar(s[i]);
		}
		else if(k<d1[i])putchar(s[(i+d2[i]-1)%n+1]);
		else if(k<d2[i])putchar(s[(i+n-d1[i]-1)%n+1]);
		else
		{
			if(d1[i]>d2[i])putchar(s[(i+d2[i]-1)%n+1]);
			else putchar(s[(i+n-d1[i]-1)%n+1]);
		}
	}
	putchar('\n');
	return 0;
}