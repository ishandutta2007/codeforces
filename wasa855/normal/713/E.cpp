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
#define ll long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int n,m,a[N],b[N],t[N],f[N];
bool QAQ(int mid)
{
	for(int i=1;i<=n;i++) f[i]=-inf;
	f[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]+f[i-1]+1>=a[i]) f[i]=mid;
		if(a[i-1]+f[i-1]+mid+1>=a[i]) f[i]=max(f[i],0);
		if(i!=2)
		{
			if(f[i-2]+a[i-2]+mid+1>=a[i]&&a[i-1]+mid-a[i]>=0) f[i]=max(f[i],a[i-1]+mid-a[i]);
		}
		if(f[i]==-inf) return 0;
	}
	// for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	return a[n]+f[n]+mid>=m;
}
bool QWQ(int mid)
{
	if(a[1]+mid+mid+1<a[2]) return 0;
	for(int i=1;i<=n;i++) f[i]=-inf;
	int go=max(0,-a[2]+mid+1);
	f[1]=mid,f[2]=max(0,a[1]+mid-a[2]);
	// cout<<go<<endl;
	for(int i=3;i<=n;i++)
	{
		if(a[i-1]+f[i-1]+1>=a[i]) f[i]=mid;
		if(a[i-1]+f[i-1]+mid+1>=a[i]) f[i]=max(f[i],0);
		if(f[i-2]+a[i-2]+mid+1>=a[i]&&a[i-1]+mid-a[i]>=0) f[i]=max(f[i],a[i-1]+mid-a[i]);
		if(f[i]==-inf) return 0;
	}
	// for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	return a[n]+f[n]+go>=m;
}
bool chk(int mid){return QAQ(mid)||QWQ(mid);}
signed main()
{
	cin>>m>>n; for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	if(n==1)
	{
		cout<<m-1<<endl;
		return 0;
	}
	int pos=0,maxd=0;
	for(int i=1;i<=n;i++)
	{
		int dis;
		if(i==1) dis=a[1]+m-a[n];
		else dis=a[i]-a[i-1];
		if(dis>maxd) maxd=dis,pos=i;
	}
	for(int i=1;i<=n;i++) t[i]=a[i];
	int cnt=0;
	for(int i=pos;i<=n;i++) a[++cnt]=t[i]-t[pos]+1;
	for(int i=1;i<pos;i++) a[++cnt]=t[i]+m-t[pos]+1;
	for(int i=1;i<=n;i++) b[i]=a[n]-a[n-i+1]+1;
	// for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	// cout<<chk(28);
	// return 0;
	int l=0,r=maxd,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}