#include<bits/stdc++.h>
using namespace std;
const int max_n=15+5;
const int max_S=1<<15|5;
int a[max_n],sum[max_S],f[max_S][max_n],id[max_n];
int dp[max_n][max_S][max_n],pre[max_n][max_S][max_n]; // about 100 MiB
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",a+i);
		int U=(1<<n)-1;
		for(int S=0;S<=U;++S)
		{
			for(int i=0;i<=n;++i)
				f[S][i]=n;
			for(int i=0;i<n;++i)
			{
				if(S>>i&1)
				{
					sum[S]+=a[i];
					f[S][i]=i;
				}
			}
			for(int i=n-1;i>=0;--i)
				f[S][i]=min(f[S][i],f[S][i+1]);
		}
		const int inf=1e9;
		for(int S=1;S<=U;++S)
		{
			for(int i=0;i<n;++i)
				dp[1][S][i]=inf;
			dp[1][S][f[S][0]]=sum[S];
		}
		int cnt=0,mask=U,pos=-1;
		for(int i=1;;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(dp[i][U][j]!=inf)
				{
					cnt=i,pos=j;
					break;
				}
			}
			if(cnt!=i)
				break;
			for(int S=1;S<=U;++S)
				for(int j=0;j<n;++j)
					dp[i+1][S][j]=inf;
			for(int S=1;S<U;++S)
				for(int j=0;j<n-1;++j)
				{
					int v=dp[i][S][j];
					if(v==inf)
						continue;
					int C=S^U;
					for(int T=C;T;T=(T-1)&C)
					{
						int k=f[T][j+1];
						if(k<n&&sum[T]>v&&dp[i+1][S|T][k]>sum[T])
						{
							dp[i+1][S|T][k]=sum[T];
							pre[i+1][S|T][k]=S|(j<<n);
						}
					}
				}
		}
		printf("%d\n",n-cnt);
		for(int i=0;i<n;++i)
			id[i]=i+1;
		while(cnt>=1)
		{
//			fprintf(stderr,"cnt=%d mask=%d pos=%d\n",cnt,mask,pos);
			int S=pre[cnt][mask][pos]&U;
			int j=pre[cnt][mask][pos]>>n;
			int T=S^mask;
			for(int i=0;i<n;++i)
			{
				if((T>>i&1)&&i!=pos)
				{
					printf("%d %d\n",id[i],id[pos]);
					id[i]=0;
					for(int j=i+1;j<n;++j)
						--id[j];
				}
			}
			--cnt,mask=S,pos=j;
		}
		for(int S=0;S<=U;++S)
			sum[S]=0;
	}
	return 0;
}