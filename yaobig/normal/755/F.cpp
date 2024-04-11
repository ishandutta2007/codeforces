#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int p[maxn+5],cc[maxn+5],cnt[3];
bool mark[maxn+5];

bitset<maxn+5> dp;

int main()
{
	int n,k; scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&p[i]);
	rep(i,1,n) if(mark[i]==0)
	{
		int now=i,c=0;
		while(mark[now]==0)
		{
			c++;
			mark[now]=1;
			now=p[now];
		}
		cnt[0]+=c/2;
		cnt[2]+=c/2;
		cnt[1]+=c%2;
		cc[c]++;
	}
	int mx=0,K=k;
	per(i,0,2) mx+=min(K,cnt[i])*i,K-=min(K,cnt[i]);
	dp[0]=1;
	rep(i,1,n) if(cc[i])
	{
		rep(j,0,25)
		{
			if(cc[i]>=(1<<j)) dp=dp | (dp<<(i*(1<<j))), cc[i]-=1<<j;
			else
			{
				dp=dp | (dp<<(i*cc[i]));
				break;
			}
		}
	}
	printf("%d %d\n",dp[k]==1?k:k+1,mx);
	return 0;
}