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
#define N 1000005
int a[N],b[N];
int f[N][2];
signed main()
{
	int n,r1,r2,r3,d;
	cin>>n>>r1>>r2>>r3>>d;
	r1=min(r1,r3);
	for(int i=1;i<=n;i++)
	{
		int x=read();
		a[i]=x*r1+r3;
		b[i]=min((x+1)*r1,r2)+r1;
	}
	f[1][0]=a[1],f[1][1]=b[1];
	for(int i=2;i<=n;i++)
	{
		f[i][0]=min(f[i-1][0]+a[i],f[i-1][0]+b[i]+d*2,f[i-1][1]+b[i]+d*2)+d;
		f[i][1]=f[i-1][0]+b[i]+d;
	}
	int ans=min(f[n][0],f[n-1][1]+a[n]+d*2);
	cout<<ans<<endl;
	return 0;
}