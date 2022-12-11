#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buf_size=1<<20;
    char buf[buf_size],*S,*T;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buf_size,stdin);
        return S!=T?*(S++):EOF;
    }
    inline int read_int()
    {
        char c;
        do
            c=read_char();
        while(c<'0'||c>'9');
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^48);
            c=read_char();
        }
        return x;
    }
}
const int max_n=4e3+5;
int sum[max_n][max_n],cost[max_n][max_n];
const int max_k=800+5;
int dp[max_k][max_n];
const int inf=1e9;
void solve(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1,pos=x;
	for(int i=x;i<=y&&i<mid;++i)
	{
		if(dp[p][i]+cost[i+1][mid]<dp[p+1][mid])
		{
			dp[p+1][mid]=dp[p][i]+cost[i+1][mid];
			pos=i;
		}
	}
	if(l<mid)
		solve(p,l,mid-1,x,pos);
	if(mid<r)
		solve(p,mid+1,r,pos,y);
}
int main()
{
	int n=IO::read_int(),k=IO::read_int();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int u=IO::read_int();
			sum[i][j]=sum[i-1][j]-sum[i-1][j-1]+sum[i][j-1]+u;
		}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			cost[i][j]=(sum[j][j]-sum[i-1][j]+sum[i-1][i-1]-sum[j][i-1])>>1;
	for(int i=0;i<=k;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<k;++i)
		solve(i,1,n,0,n-1);
	printf("%d\n",dp[k][n]);
	return 0;
}