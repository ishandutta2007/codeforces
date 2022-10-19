#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int sum[30][N];
char s[N],t[N];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=0;i<26;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum[i][j]=sum[i][j-1]+(s[j]==(i+'a'));
		}
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",t+1);
		int l=strlen(t+1);
		int ans=0;
		for(int i=0;i<26;i++)
		{
			int tot=0;
			for(int j=1;j<=l;j++)
				if(t[j]==(i+'a'))
					tot++;
			int k=lower_bound(sum[i]+1,sum[i]+n+1,tot)-sum[i];
			ans=max(ans,k);	
		}
		printf("%d\n",ans);
	}
	return 0;
}