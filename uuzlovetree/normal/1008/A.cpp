#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;
char s[maxn];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	bool ok=1;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='n')continue;
		bool yes=0;
		if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
		{
			if(s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u')yes=1,i++;
			else ok=0;
		}
		else yes=1;
	}
	if(ok)puts("YES");else puts("NO");
	return 0;
}