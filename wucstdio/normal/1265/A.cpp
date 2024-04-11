#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=(int)strlen(s+1);
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='?')
			{
				if(s[i-1]!='a'&&s[i+1]!='a')s[i]='a';
				if(s[i-1]!='b'&&s[i+1]!='b')s[i]='b';
				if(s[i-1]!='c'&&s[i+1]!='c')s[i]='c';
			}
			if(s[i]==s[i-1])
			{
				flag=0;
				break;
			}
		}
		if(!flag)printf("-1\n");
		else printf("%s\n",s+1);
	}
	return 0;
}