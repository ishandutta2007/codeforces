#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n,m,sum[26][200005];
ll ans[26];
char s[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<26;j++)sum[j][i]=sum[j][i-1];
			sum[s[i]-'a'][i]++;
		}
		memset(ans,0,sizeof(ans));
		while(m--)
		{
			int x;
			scanf("%d",&x);
			for(int i=0;i<26;i++)ans[i]+=sum[i][x];
		}
		for(int i=0;i<26;i++)ans[i]+=sum[i][n];
		for(int i=0;i<26;i++)printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}