#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
char s[105];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=0;
		for(int i=1;i<n;i++)
		{
			scanf("%s",s+1);
			ans+=s[m]=='R';
		}
		scanf("%s",s+1);
		for(int i=1;i<m;i++) ans+=s[i]=='D';
		printf("%d\n",ans);
	}
	return 0;
}