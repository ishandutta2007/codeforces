#include<bits/stdc++.h>
const int Maxn=1005;
using namespace std;
char ch[Maxn][Maxn];
int n,m,len[Maxn],prefix[Maxn],suffix[Maxn],sta[Maxn],maxi[Maxn][Maxn];
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
			if(ch[i][j]==ch[i][j+1])
				maxi[i][j]=maxi[i][j+1]+1;
			else maxi[i][j]=1;
	for(int j=1;j<=m;j++)
	{
		int now=0;
		for(int i=1;i<=n;i++) 
			if(ch[i][j]==ch[i-1][j])
			{
				len[now]++;
				prefix[i]=min(prefix[i-1],maxi[i][j]);
			}
			else
			{
				len[++now]=1;
				prefix[i]=maxi[i][j];
				sta[now]=i;
			}
		for(int i=n;i>=0;i--)
			if(ch[i][j]==ch[i+1][j])
				suffix[i]=min(suffix[i+1],maxi[i][j]);
			else suffix[i]=maxi[i][j];
		for(int i=2;i<now;i++)
			if(len[i]<=len[i-1]&&len[i]<=len[i+1])
				ans+=min(suffix[sta[i]],min(suffix[sta[i-1]+len[i-1]-1-len[i]+1],prefix[sta[i+1]+len[i]-1]));
	}
	printf("%lld",ans);
	return 0;
}