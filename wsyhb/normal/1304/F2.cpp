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
        char c=read_char();
        bool neg=false;
        while(c<'0'||c>'9')
        {
            neg=(c=='-');
            c=read_char();
        }
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^'0');
            c=read_char();
        }
        return neg?-x:x;
    }
}
const int max_n=50+5;
const int max_m=2e4+5;
int s[max_n][max_m],dp[max_n][max_m];
const int inf=1e9;
int que[max_m],head,tail;
int main()
{
	int n=IO::read_int(),m=IO::read_int(),k=IO::read_int();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int a=IO::read_int();
			s[i][j]=s[i][j-1]+a;
		}
	for(int i=1;i<=m-k+1;++i)
		dp[1][i]=s[1][i+k-1]-s[1][i-1];
	for(int i=2;i<=n;++i)
	{
		int now=-inf;
		head=1,tail=0;
		for(int x=1;x<=m-k+1;++x)
		{
			int y=x-k;
			if(y>=1)
				now=max(now,dp[i-1][y]+s[i][y+k-1]-s[i][y-1]);
			while(head<=tail&&que[head]<x-k+1)
				++head;
			while(head<=tail&&dp[i-1][que[tail]]-s[i][que[tail]-1]<dp[i-1][x]-s[i][x-1])
				--tail;
			que[++tail]=x;
			dp[i][x]=max(now+s[i][x+k-1]-s[i][x-1],dp[i-1][que[head]]-s[i][que[head]-1]+s[i][x+k-1]);
		}
		now=-inf;
		head=1,tail=0;
		for(int x=m-k+1;x>=1;--x)
		{
			int y=x+k;
			if(y<=m-k+1)
				now=max(now,dp[i-1][y]+s[i][y+k-1]-s[i][y-1]);
			while(head<=tail&&que[head]>x+k-1)
				++head;
			while(head<=tail&&dp[i-1][que[tail]]+s[i][que[tail]+k-1]<dp[i-1][x]+s[i][x+k-1])
				--tail;
			que[++tail]=x;
			dp[i][x]=max(dp[i][x],max(now+s[i][x+k-1]-s[i][x-1],dp[i-1][que[head]]+s[i][que[head]+k-1]-s[i][x-1]));
		}
	}
	int ans=-inf;
	for(int i=1;i<=m;++i)
		ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}