#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x,int y)
{
	// printf("%d %d\n",x,y);
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
struct Mat
{
	int a[3][3];
};
Mat Mul(Mat x,Mat y)
{
	Mat ans; memset(ans.a,0,sizeof(ans.a));
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			for(int k=1;k<=2;k++)
			{
				ans.a[i][j]=add(ans.a[i][j],mul(x.a[i][k],y.a[k][j]));
			}
		}
	}
	return ans;
}
Mat Qpow(Mat x,int y)
{
	Mat ans; memset(ans.a,0,sizeof(ans.a));
	ans.a[1][1]=ans.a[2][2]=1;
	while(y)
	{
		if(y&1) ans=Mul(ans,x);
		x=Mul(x,x);
		y>>=1;
	}
	return ans;
}
signed main()
{
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	if(n>m) swap(n,m);
	if((n*m)%2==1)
	{
		printf("%lld\n",qpow((r-l+1)%mod,n*m));
	}
	else
	{
		int y=r/2-(l-1)/2;
		int x=(r-l+1)-y;
		// printf("%d %d\n",x,y);
		Mat ans; memset(ans.a,0,sizeof(ans.a));
		ans.a[1][1]=y; ans.a[1][2]=x;ans.a[2][1]=x;ans.a[2][2]=y;
		ans=Qpow(ans,n*m);
		// for(int i=1;i<=2;i++)
		// {
			// for(int j=1;j<=2;j++) printf("%d ",ans.a[i][j]);
			// cout<<"\n";
		// }
		Mat a; memset(a.a,0,sizeof(a.a));
		a.a[1][2]=1;
		a=Mul(a,ans);
		printf("%lld\n",a.a[1][2]);
	}
	return 0;
}