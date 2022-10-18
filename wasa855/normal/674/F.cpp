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
#define N 1005
unsigned c[N],pp[N];
int n,p,q;
unsigned C(int x,int y)
{
	assert(x==n);
	if(c[y]) return c[y];
	for(int i=1;i<=y;i++) pp[i]=n-i+1;
	for(int i=1;i<=y;i++)
	{
		unsigned x=i;
		for(int j=1;x!=1&&j<=y;j++)
		{
			int R=__gcd(x,pp[j]);
			x/=R,pp[j]/=R;
		}
	}
	unsigned ans=1;
	for(int i=1;i<=y;i++) ans*=pp[i];
	return c[y]=ans;
}
signed main()
{
	cin>>n>>p>>q;
	unsigned ans=0;
	int A=min(n-1,p);
	for(int i=1;i<=q;i++)
	{
		unsigned r=1,res=0;
		for(int j=0;j<=A;j++)
		{
			res+=C(n,j)*r;
			r*=i;
		}
		ans^=(res*i);
	}
	cout<<ans<<endl;
	return 0;
}