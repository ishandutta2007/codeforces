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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
#define N 100005
int a[N],b[N],n,k,minn[N];
void solve1()
{
	int sum=a[n],minn=inf;
	for(int i=1;i<n;i++) sum+=a[i],minn=min(minn,b[i]);
	cout<<max(0LL,sum-minn,a[n]-b[n])<<endl;
}
void solve2()
{
	int ans=0,sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,sum-b[i]);
		sum-=a[i];
	}
	cout<<ans<<endl;
}
int sum[N];
void solve3()
{
	int ans=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	minn[n]=b[n]; for(int i=n-1;i>=1;i--) minn[i]=min(minn[i+1],b[i]);
	
	for(int i=1;i<n;i++) ans=max(ans,sum[n]-b[i]-minn[i+1]);
	for(int i=1;i<n;i++) ans=max(ans,sum[n-1]-b[i]+max(0LL,a[n]-b[n]));
	for(int i=2;i<=n;i++) ans=max(ans,sum[n]-b[1]-a[i]+max(0LL,a[i]-b[i]));
	
	// cout<<ans<<endl;
	
	for(int i=2;i<=n;i++) ans=max(ans,sum[n]-sum[i-1]-b[i]+max(0LL,sum[i-1]-b[1]));
	
	// ans=max(ans,sum[n]-minn[1]-b[1]);
	cout<<ans<<endl;
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	if(k>=2) {solve1(); return 0;}
	if(k==0) {solve2(); return 0;}
	if(k==1) {solve3(); return 0;}
	return 0;
}