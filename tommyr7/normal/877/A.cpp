#include <bits/stdc++.h>
#define Maxn 107
using namespace std;
char s[Maxn];
int cnt=0;
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<len;i++)
	{
		if (i+4<len)
		{
			if (s[i]=='D'&&s[i+1]=='a'&&s[i+2]=='n'&&s[i+3]=='i'&&s[i+4]=='l') ++cnt;
		}
		if (i+3<len)
		{
			if (s[i]=='O'&&s[i+1]=='l'&&s[i+2]=='y'&&s[i+3]=='a') ++cnt;
		}
		if (i+4<len)
		{
			if (s[i]=='S'&&s[i+1]=='l'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='a') ++cnt;
		}
		if (i+2<len)
		{
			if (s[i]=='A'&&s[i+1]=='n'&&s[i+2]=='n') ++cnt;
		}
		if (i+5<len)
		{
			if (s[i]=='N'&&s[i+1]=='i'&&s[i+2]=='k'&&s[i+3]=='i'&&s[i+4]=='t'&&s[i+5]=='a') ++cnt;
		}
	}
	if (cnt==1) printf("YES\n"); else printf("NO\n");
	return 0;
}