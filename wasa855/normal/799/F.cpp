#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define ull unsigned long long
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
#define N 200005
ull a[N];
map<ull,ll> b,c;
int ct[N];
signed main()
{
	int n,m; cin>>n>>m;
	int lmin=inf,rmax=0;
	for(int i=1;i<=n;i++)
	{
		int l=read(),r=read();
		lmin=min(lmin,l),rmax=max(rmax,r);
		ull x=((ull)rnd()<<32)|rnd();
		a[l+1]^=x,a[r+1]^=x;
		ct[l]++,ct[r+1]--;
	}
	for(int i=1;i<=m;i++) ct[i]+=ct[i-1];
	for(int i=1;i<=m;i++) a[i]^=a[i-1];
	for(int i=1;i<=m;i++) a[i]^=a[i-1];
	// for(int i=1;i<=m;i++) printf("%llu ",a[i]); cout<<"\n";
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		c[a[i]]++,b[a[i]]+=i-1;
		ans+=i*c[a[i]]-b[a[i]];
	}
	for(int i=1;i<=m;i++)
	{
		if(ct[i]) continue;
		int r=i;
		while(r<m&&!ct[r+1]) r++;
		// printf("%d %d\n",i,r);
		for(int j=1;j<=r-i+1;j++) ans-=1LL*j*(j+1)/2;
		i=r;
	}
	cout<<ans<<endl;
	return 0;
}