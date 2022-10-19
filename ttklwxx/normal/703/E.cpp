#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
long long pri[100005];
int tsl[100005],cnt;
long long ys[1000005],tmp;
int sl[7005][1005]; 
int nown[1005];
unordered_map<long long,int>ma;
void dfs(int x,long long now)
{
	if(x==cnt+1)
	{
		ys[++tmp]=now;
		for(int j=1;j<=cnt;j++)sl[tmp][j]=nown[j];
		return;
	}
	for(int i=0;i<=tsl[x];i++)
	{
		nown[x]=i;
		dfs(x+1,now);
		now*=pri[x];
	}
}
long long dp[1005][7005];
int las[1005][7005];
int qans[1005],ttt;
long long a[1005];
void findgz(int x,int y)
{
	if(x==0)return;
	if(las[x][y]!=y)qans[++ttt]=x;
	findgz(x-1,las[x][y]); 
}
long long cm[1005][1005];
int sla[1005][1005];
signed main()
{
	int n;
	long long k,tk;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(); 
	}
	long long minn=1121131433448687LL;
	int mpos;
	for(int i=1;i<=n;i++)
	{
	    if(a[i]<minn)
	    {
	        minn=a[i];
	        mpos=i;
	    }
	}
	if(k==1)
	{
	    printf("1\n%d\n",mpos);
	    return 0;
	} 
	tk=k;
	for(long long i=2;i*i<=tk;i++)
	{
		if(tk%i!=0)continue;
		pri[++cnt]=i;
		while(tk%i==0)
		{
			tk/=i;
			tsl[cnt]++;
		}
	}
	if(tk>1)
	{
		pri[++cnt]=tk;
		tsl[cnt]=1; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			long long sth=a[i];
			int nowa=0;
			while(sth%pri[j]==0)sth/=pri[j],nowa++;
			sla[i][j]=nowa;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		cm[i][0]=1;
		for(int j=1;j<=tsl[i];j++)cm[i][j]=cm[i][j-1]*pri[i];
	}
	dfs(1,1);
	//sort(ys+1,ys+tmp+1);
	for(int i=1;i<=tmp;i++)ma[ys[i]]=i;
	//for(int i=1;i<=tmp;i++)printf("%lld ",ys[i]);
	//printf("\n");
	for(int i=0;i<=n;i++)for(int j=1;j<=tmp;j++)dp[i][j]=2000000000000000000LL;
	dp[0][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=tmp;j++)
		{
			if(dp[i-1][j]==2000000000000000000LL)continue;
			//printf("%lld %lld %lld\n",i-1,j,dp[i-1][j]);
			if(dp[i-1][j]<dp[i][j])
			{
				dp[i][j]=dp[i-1][j];
				las[i][j]=j;
			}
			long long tgcd=1;
			for(int l=1;l<=cnt;l++)
			{
				tgcd=tgcd*cm[l][min(sl[j][l]+sla[i][l],tsl[l])];
			}
			int sth=ma[tgcd];
			//assert(sth!=0)
			///printf("???%lld\n",sth);
			if(dp[i][sth]>dp[i-1][j]+a[i]+1000000000000000LL)
			{
				dp[i][sth]=dp[i-1][j]+a[i]+1000000000000000LL;
				las[i][sth]=j;
			}
		}
	}
	if(dp[n][tmp]==2000000000000000000LL)
	{
		printf("-1\n");
		return 0;
	}
	//printf("%lld\n",dp[n][tmp]);
	findgz(n,tmp);
	sort(qans+1,qans+ttt+1);
	printf("%d\n",ttt);
	for(int i=1;i<=ttt;i++)printf("%d ",qans[i]);
	printf("\n");
	return 0;
}