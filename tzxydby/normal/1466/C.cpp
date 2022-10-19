#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N];
int n,ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i>1&&s[i]!='@'&&s[i-1]!='@'&&s[i]==s[i-1])
			{
				s[i]='@';
				ans++;
			}
			if(i>2&&s[i]!='@'&&s[i-2]!='@'&&s[i]==s[i-2])
			{
				s[i]='@';
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}