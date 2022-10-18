#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 2005
int f[N][N],a[N];
signed main()
{
	int n,h,l,r;
	cin>>n>>h>>l>>r;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int j=0;j<=n;j++) for(int i=0;i<h;i++) f[j][i]=-INF;
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<h;j++)
		{
			int d=(j+a[i])%h;
			if(l<=d&&d<=r) f[i][d]=max(f[i][d],f[i-1][j]+1);
			else f[i][d]=max(f[i][d],f[i-1][j]);
			d=(j+a[i]-1)%h;
			if(l<=d&&d<=r) f[i][d]=max(f[i][d],f[i-1][j]+1);
			else f[i][d]=max(f[i][d],f[i-1][j]);
		}
	}
	int ans=0;
	for(int i=0;i<h;i++) if(f[n][i]>ans) ans=f[n][i];
	cout<<ans<<endl;
	return 0;
}

//