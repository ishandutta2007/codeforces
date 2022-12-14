#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1<<30;

int dp[100100][27];

bool ok[26][26];

char ch[100100];

int main()
{
	int M;
	scanf("%s",ch);
	int N=strlen(ch);
	scanf("%d",&M);
	for(int i=0;i<26;i++) for(int j=0;j<26;j++) ok[i][j]=true;
	for(int i=0;i<M;i++)
	{
		char buf[3];
		scanf("%s",buf);
		int i1=buf[0]-'a',i2=buf[1]-'a';
		ok[i1][i2]=false,ok[i2][i1]=false;
	}
	for(int i=0;i<26;i++) dp[0][i]=inf;
	dp[0][ch[0]-'a']=0;
	dp[0][26]=1;
	for(int i=1;i<N;i++)
	{
		int id=ch[i]-'a';
		for(int j=0;j<27;j++) dp[i][j]=dp[i-1][j]+1;
		for(int j=0;j<26;j++)
		{
			if(ok[id][j]==false) continue;
			dp[i][id]=min(dp[i-1][j],dp[i][id]);
		}
		dp[i][id]=min(dp[i][id],dp[i-1][26]);
	}
	int ans=1<<30;
	for(int i=0;i<27;i++)
	{
		ans=min(ans,dp[N-1][i]);
	}
	printf("%d\n",ans);
	return 0;
}