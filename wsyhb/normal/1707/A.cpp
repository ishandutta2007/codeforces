#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n];
char s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			s[i]='0';
		}
		s[n+1]='\0';
		int cnt=0;
		for(int i=n;i>=1;--i)
		{
			if(a[i]<=cnt)
				s[i]='1';
			else if(cnt<q)
			{
				s[i]='1';
				++cnt;
			}
		}
		printf("%s\n",s+1);
	}
	return 0;
}