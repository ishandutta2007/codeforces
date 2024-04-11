#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8

#define _ 0
using namespace std;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x ^= x << 13;
		x ^= x >> 7;
		x ^= x << 17;
		return x; 
	}
	size_t operator () (uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); // 
		return splitmix64(x + FIXED_RANDOM);
	}
};
#define int LL
vector<int> v;
int n;
int a[MAXN];
int dp[MAXN];
unordered_map<LL,int,custom_hash> mp;
void init()
{

}
//y_i ^ x_j < y_j ^ x_i
// 0 0 1 0
// 1 1 0 1
// 1 0 1 1
// 0 1 0 0
void work()
{
	mp.clear();
	scanf("%lld",&n);
	for (int i=0;i<=n;i++)
		dp[i]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		for (int j=0;j<30;j++)
		{
			int y=(a[i]>>j)%2;
			int x=((i-1)>>j)%2;
			LL p=((((i-1)^a[i])>>(j+1))<<(j+1));
			//cout<<i<<' '<<j<<' '<<x<<' '<<y<<' '<<mp[(y^1)*2+x][j][p]<<endl;
			dp[i]=max(dp[i],mp[(y^1)*2+x+j*4+(p<<10)]+1);
			//WRT(dp[i])
		}
		for (int j=0;j<30;j++)
		{
			int y=(a[i]>>j)%2;
			int x=((i-1)>>j)%2;
			LL p=((((i-1)^a[i])>>(j+1))<<(j+1));
			mp[x*2+y+j*4+(p<<10)]=max(mp[x*2+y+j*4+(p<<10)],dp[i]);
			//cout<<'!'<<p<<' '<<x<<' '<<y<<endl;
		}
	}
	int mx=0;
	for (int i=1;i<=n;i++)
		mx=max(mx,dp[i]);
	printf("%lld\n",mx);
}

signed main()
{
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		//printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}