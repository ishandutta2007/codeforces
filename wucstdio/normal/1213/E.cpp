#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[5],t[5];
void check(char a,char b,char c)
{
	if(s[1]==a&&s[2]==b)return;
	if(s[1]==b&&s[2]==c)return;
	if(t[1]==a&&t[2]==b)return;
	if(t[1]==b&&t[2]==c)return;
	for(int i=1;i<=n;i++)putchar(a);
	for(int i=1;i<=n;i++)putchar(b);
	for(int i=1;i<=n;i++)putchar(c);
	putchar('\n');
	exit(0);
}
int main()
{
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	printf("YES\n");
	if(s[1]==s[2]&&t[1]==t[2])
	{
		if(s[1]==t[1])
		{
			for(char c='a';c<='c';c++)
			{
				if(c==s[1])continue;
				t[1]=c;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		  putchar(s[1]),putchar(t[1]);
		for(char c='a';c<='c';c++)
		{
			if(c==s[1]||c==t[1])continue;
			for(int i=1;i<=n;i++)putchar(c);
		}
		putchar('\n');
		return 0;
	}
	if(t[1]==t[2])
	{
		swap(t[1],s[1]);
		swap(t[2],s[2]);
	}
	if(s[1]==s[2])
	{
		if(s[1]==t[2])swap(t[1],t[2]);
		if(s[1]==t[1])
		{
			for(char c='a';c<='c';c++)
			{
				if(c!=s[1]&&c!=t[2])
				{
					for(int i=1;i<=n;i++)
					  putchar(s[1]),putchar(c);
					for(int i=1;i<=n;i++)
					  putchar(t[2]);
					putchar('\n');
					break;
				}
			}
		}
		else
		{
			for(char c='a';c<='c';c++)
			{
				if(c!=s[1])
				{
					for(int i=1;i<=n;i++)
					  putchar(c),putchar(s[1]);
					for(int i=1;i<=n;i++)
					  putchar(c==t[1]?t[2]:t[1]);
					putchar('\n');
					break;
				}
			}
		}
		return 0;
	}
	check('a','b','c');
	check('a','c','b');
	check('b','a','c');
	check('b','c','a');
	check('c','a','b');
	check('c','b','a');
	return 0;
}