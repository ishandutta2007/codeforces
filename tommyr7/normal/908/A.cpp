#include <bits/stdc++.h>
using namespace std;
char s[107];
int ans=0,n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)
	{
		if (s[i]>='a'&&s[i]<='z')
		{
			if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') ++ans;
		} else
		if (s[i]>='0'&&s[i]<='9')
		{
			if (s[i]!='0'&&s[i]!='2'&&s[i]!='4'&&s[i]!='6'&&s[i]!='8') ++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}