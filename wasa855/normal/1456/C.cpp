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
#define N 500005
int a[N],sum[N],s[N],pos[N];
signed main()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) sum[i]=sum[i+1]+a[i],s[i]=s[i+1]+sum[i+1];
	int cnt=0;
	for(int i=1;i<=n;i+=k+1)
	{
		for(int j=i;j<=min(i+k,n);j++) a[j]*=cnt,pos[j]=cnt+1;
		cnt++;
	}
	int ans=-INF;
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	for(int i=0;i<=n;i++)
	{
		int R=a[i]+s[i+1]+pos[i]*sum[i+1];
		ans=max(ans,R);
	}
	cout<<ans<<endl;
	return 0;
}