#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1550;
const int inf=1e9+7;
int a[N];
int seg[N],dp[N][N];
vector<int> st;
struct BIT
{
	int mx[N];
	void init(){ for(int i=0;i<N;i++) mx[i]=-inf;}
	BIT(){ init();}
	void Set(int i, int f){ i++;for(;i;i-=i&-i) mx[i]=max(mx[i],f);}
	int Get(int i){ i++;int ans=-inf;for(;i<N;i+=i&-i) ans=max(ans,mx[i]);return ans;}
} Tree[N];
int sum[N];
bool Check(int n, int m, int k, int mid)
{
	int i,j;
	Tree[0].init();
	Tree[0].Set(0,0);
	dp[0][0]=0;
	for(i=1;i<=m;i++) dp[0][i]=-inf;
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]<=mid);
	for(i=1;i<=m;i++) Tree[i].init();
	for(i=1;i<=n;i++)
	{
		if(seg[i]<=i)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j]=max(Tree[j-1].Get(seg[i]-1)+sum[i],dp[i-1][j]);
				if(dp[i][j]>=k) return 1;
			}
			for(j=1;j<=m;j++) Tree[j].Set(i,dp[i][j]-sum[i]);
		}
		else
		{
			for(j=1;j<=m;j++) dp[i][j]=dp[i-1][j],Tree[j].Set(i,dp[i][j]-sum[i]);
		}
		Tree[0].Set(i,-sum[i]);
	}
	return 0;
}
int main()
{
	int n,s,m,k,i,l,r;
	scanf("%i %i %i %i",&n,&s,&m,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),seg[i]=n+1,st.pb(a[i]);
	while(s--) scanf("%i %i",&l,&r),seg[r]=min(seg[r],l);
	sort(st.begin(),st.end());
	int top=n-1,bot=0,mid,ans=-1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(n,m,k,st[mid])) ans=st[mid],top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",ans);
	return 0;
}