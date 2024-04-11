#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define INF ((int)1e18)
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
#define N 100005
struct Node
{
	int a,s[10];
};
bool cmp(Node x,Node y)
{
	return x.a>y.a;
}
Node a[N];
int f[N][130];
int cnt[130];
signed main()
{
	int n,p,m;
	cin>>n>>p>>m;
	for(int i=1;i<=n;i++) a[i].a=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p;j++) a[i].s[j]=read();
	}
	sort(a+1,a+n+1,cmp);
	int lim=1<<p;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<lim;j++) f[i][j]=-INF;
	}
	for(int i=0;i<lim;i++)
	{
		for(int j=0;j<p;j++)
		{
			if(i&(1<<j)) cnt[i]++;
		}
	}
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<lim;j++)
		{
			f[i][j]=f[i-1][j]+(i-cnt[j]<=m?a[i].a:0);
			for(int k=1;k<=p;k++)
			{
				if(!(j&(1<<(k-1)))) continue;
				int R=f[i-1][j^(1<<(k-1))]+a[i].s[k];
				if(R>f[i][j]) f[i][j]=R;
			}
		}
	}
	cout<<f[n][lim-1]<<endl;
	return 0;
}