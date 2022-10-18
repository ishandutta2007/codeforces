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
int lcm(int x,int y) {return x/__gcd(x,y)*y;}
signed main()
{
	int n,ax,bx,ay,by;
	cin>>n>>ax>>ay>>bx>>by;
	// ax=abs(ax),bx=abs(bx),ay=abs(ay),by=abs(by);
	if(bx==0||by==0) swap(ax,bx),swap(ay,by);
	if(ax==0)
	{
		ax=abs(ax),bx=abs(bx),ay=abs(ay),by=abs(by);
		if(bx*ay==n)
		{
			cout<<"YES\n";
			for(int i=0;i<bx;i++) for(int j=0;j<ay;j++) printf("%lld %lld\n",i,j);
		}
		else cout<<"NO\n";
		return 0;
	}
	if(ay==0)
	{
		ax=abs(ax),bx=abs(bx),ay=abs(ay),by=abs(by);
		if(by*ax==n)
		{
			cout<<"YES\n";
			for(int i=0;i<ax;i++) for(int j=0;j<by;j++) printf("%lld %lld\n",i,j);
		}
		else cout<<"NO\n";
		return 0;
	}
	int A=lcm(ax,bx);
	int lb=abs(A/ax*ay-A/bx*by);
	int B=lcm(ay,by);
	int la=abs(B/ay*ax-B/by*bx);
	// int la=__gcd(ax,ay);
	// printf("%d - %d\n",B/ay*ax,B/by*bx);
	// printf("%d %d\n",la,lb);
	int ga=__gcd(ax,bx); ga=abs(ga);
	int gb=__gcd(ay,by); gb=abs(gb);
	if(lb<=n&&ga*lb==n)
	{
		cout<<"YES\n";
		for(int i=0;i<ga;i++) for(int j=0;j<lb;j++) printf("%lld %lld\n",i,j);
	}
	else if(la<=n&&gb*la==n)
	{
		cout<<"YES\n";
		for(int i=0;i<la;i++) for(int j=0;j<gb;j++) printf("%lld %lld\n",i,j);
	}
	else cout<<"NO\n";
	return 0;
}