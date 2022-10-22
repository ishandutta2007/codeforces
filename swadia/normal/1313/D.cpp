#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int l[MAXN],r[MAXN];
typedef pair<int,int> pii;
vector<pii> v;
int n,m,k;
int mp[1000];
int lbit[1000];
int dp[MAXN][300];
int msk[MAXN];
int main()
{
	for (int i=0;i<MAXN;i++)
		for (int j=0;j<300;j++)
			dp[i][j]=-INF;
	dp[0][0]=0;
	for (int i=0;i<(1<<9);i++)
	{
		int cnt=0;
		for (int j=0;j<8;j++)
			if (i & (1<<j))
			{
				mp[i]++;
			}
			else if (lbit[i]==0)
			{
				lbit[i]=(1<<j);
				//cout<<i<<' '<<lbit[i]<<endl;
			}
	}
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		v.push_back({l[i]-1,i});
		v.push_back({r[i],-i});
	}
	sort(v.begin(),v.end());
	int tim=0;
	int posmsk=0;
	int ans=0;
	int lst=0;
	for (auto p:v)
	{
		//cout<<p.first<<' '<<p.second<<endl;
		tim++;
		//WRT(tim);
		if (p.second<0)
		{
			for (int j=0;j<(1<<8);j++)
				if (j & msk[-p.second])
					dp[tim][j ^ msk[-p.second]]=max(dp[tim][j ^ msk[-p.second]],dp[tim-1][j]+max(0,p.first-lst)*(mp[j]&1));
				else
				{
					dp[tim][j]=max(dp[tim][j],dp[tim-1][j]+(p.first-lst)*(mp[j]&1));
				}
			posmsk ^=  msk[-p.second];
		}
		else
		{
			msk[p.second]=lbit[posmsk];
			//WRT(msk[p.
			posmsk ^= msk[p.second];
			for (int j=0;j<(1<<8);j++)
				if ((j & msk[p.second]) == 0)
				{
					dp[tim][j ^ msk[p.second]]=max(dp[tim][j ^ msk[p.second]],dp[tim-1][j]+(max(0,p.first-lst))*(mp[j]&1));
					dp[tim][j]=max(dp[tim][j],dp[tim-1][j]+(p.first-lst)*(mp[j]&1));
					//cout<<j<<' '<<dp[tim][j]<<' '<<dp[tim-1][j]<<' '<<tim-1<<endl;
				}
		}
		//WRT(dp[tim][0]);
		//WRT(posmsk);
		
		lst=p.first;
	}
	cout<<dp[2*n][0];
	return ~~(0^_^0);
}