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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1005
int a[N][N],sum[N],tmp[N],n,k;
signed main()
{
	cin>>k>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) a[i][j]=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) sum[i]+=a[i][j];
	// for(int i=1;i<=n;i++) printf("%d%c",sum[i]," \n"[i==n]);
	for(int i=1;i<n;i++) tmp[i]=sum[i+1]-sum[i];
	sort(tmp+1,tmp+n); int val=tmp[n/2];
	int bad=0;
	for(int i=2;i<n;i++)
	{
		if(sum[i]-sum[i-1]!=val&&sum[i+1]-sum[i]!=val) bad=i;
	}
	assert(bad);
	int sqrsum=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=bad&&i+1!=bad&&i+2!=bad)
		{
			int s1=0,s2=0,s3=0;
			for(int j=1;j<=k;j++) s1+=a[i][j]*a[i][j];
			for(int j=1;j<=k;j++) s2+=a[i+1][j]*a[i+1][j];
			for(int j=1;j<=k;j++) s3+=a[i+2][j]*a[i+2][j];
			sqrsum=(s1+s3-s2-s2);
			break;
		}
	}
	// cout<<sqrsum<<endl;
	int ned=val-(sum[bad]-sum[bad-1]);
	for(int i=1;i<=k;i++)
	{
		a[bad][i]+=ned;
		int s1=0,s2=0,s3=0;
		for(int j=1;j<=k;j++) s1+=a[bad-1][j]*a[bad-1][j];
		for(int j=1;j<=k;j++) s2+=a[bad][j]*a[bad][j];
		for(int j=1;j<=k;j++) s3+=a[bad+1][j]*a[bad+1][j];
		if(s1+s3-s2-s2==sqrsum) return printf("%d %d\n",bad-1,a[bad][i]),0;
		a[bad][i]-=ned;
	}
	
	return 0;
}