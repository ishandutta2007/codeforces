#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int N=2e5+5;
char s[N];
int c[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		int m=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=s[i-1]) m++;
			c[m]++;
		}
		if(m==1)
		{
			c[1]=0;
			printf("%d\n",(n+2)/3);
			continue;
		}
		if(m>1&&s[1]==s[n])
		{
			c[1]+=c[m];
			c[m--]=0;
		}
		int ans=0;
		for(int i=1;i<=m;i++) ans+=c[i]/3,c[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}