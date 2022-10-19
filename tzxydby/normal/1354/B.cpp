#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int nxt[N][3],n,t;
char s[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int j=0;j<3;j++)
			nxt[n+1][j]=n+1;
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<3;j++)
				nxt[i][j]=nxt[i+1][j];
			nxt[i][s[i]-'1']=i;
		}
		int ans=n+1;
		for(int i=1;i<=n;i++)
		{
			int x=i;
			for(int j=0;j<3;j++)
				x=max(x,nxt[i][j]);
			if(x<=n)
				ans=min(ans,x-i+1);
		}
		if(ans==n+1)
			ans=0;
		printf("%d\n",ans);
	}
	return 0;
}