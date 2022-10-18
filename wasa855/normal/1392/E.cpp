#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 30
int a[N][N];
signed main()
{
	int n=read(),cnt=0;
	int maxn=0;
	for(int j=n;j>=1;j--)
	{
		if(j%2==0)
		{
			for(int i=n;i>=1;i--) a[i][j]=1LL<<(cnt+n-i),maxn=max(maxn,cnt+n-i);
			cnt+=2;
		}
	}
//	cout<<maxn<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%lld ",a[i][j]);
		cout<<endl;
	}
	int Q=read();
	while(Q--)
	{
		int d=read();
		int x=1,y=1; printf("%lld %lld\n",x,y);
		int tp=51; while(tp>=0&&!((d>>tp)&1)) tp--;
		while(x!=n&&y!=n)
		{
			if(y%2==1)
			{
				if(tp!=-1&&(1LL<<tp)==a[x][y+1]) y++,tp--;
				else x++;
			}
			else
			{
				if(tp!=-1&&(1LL<<tp)==a[x+1][y]) x++,tp--;
				else y++;
			}
			while(tp>=0&&!((d>>tp)&1)) tp--;
			printf("%lld %lld\n",x,y);
//			cout<<tp<<endl;
		}
		while(x!=n)
		{
			x++;
			printf("%lld %lld\n",x,y);
		}
		while(y!=n)
		{
			y++;
			printf("%lld %lld\n",x,y);
		}
		fflush(stdout);
	}
	return 0;
}