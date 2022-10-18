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
#define N 300005
pii a[N];
int n;
bool chk(int val)
{
	int u=inf,d=0,l=0,r=inf,x=inf,y=-inf;
	for(int i=1;i<=n;i++)
	{
		u=min(u,a[i].sec+val),d=max(d,a[i].sec-val);
		l=max(l,a[i].fir-val),r=min(r,a[i].fir+val);
		x=min(x,a[i].sec-a[i].fir+val);
		y=max(y,a[i].sec-a[i].fir-val);
	}
	// printf("%d : %d %d %d %d %d %d\n",val,u,d,l,r,x,y);
	// for(int i=1;i<=n;i++) printf("%d\n",a[i].sec-val);
	if(d>u) return 0;
	if(l>r) return 0;
	if(y>x) return 0;
	// x \in [l,r], y \in [u,d], y-x \in [x,y]
	int X=u-x,Y=u-y;
	if(max(l,X)<=min(r,Y)) return 1; //  x=X, y=d;
	if(X>r)
	{
		if(u-X+r>=d) return 1; // x=r, y=u-X+r
	}
	return 0;
}
void print(int val)
{
	int u=inf,d=0,l=0,r=inf,x=inf,y=-inf;
	for(int i=1;i<=n;i++)
	{
		u=min(u,a[i].sec+val),d=max(d,a[i].sec-val);
		l=max(l,a[i].fir-val),r=min(r,a[i].fir+val);
		x=min(x,a[i].sec-a[i].fir+val);
		y=max(y,a[i].sec-a[i].fir-val);
	}
	y=max(y,d-r),x=min(x,u-l);
	int X=max(l,d-y),Y=y+X;
	if(!X&&!Y) X++,Y++;
	for(int i=1;i<=X;i++) cout<<'B';
	for(int i=1;i<=Y;i++) cout<<'N';
	// int X=u-x,Y=u-y;
	// printf("%d : %d %d %d %d %d %d\n",val,u,d,l,r,x,y);
	// if(max(l,X)<=min(r,Y))
	// {
		// for(int i=1;i<=X;i++) cout<<'B';
		// for(int i=1;i<=u;i++) cout<<'N';
	// } //  x=X, y=u;
	// if(X>r)
	// {
		// if(u-X+r>=d)
		// {
			// for(int i=1;i<=r;i++) cout<<'B';
			// for(int i=1;i<=u-X+r;i++) cout<<'N';
		// } // x=r, y=u-X+r
	// }
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int ca=0,cb=0;
		string s; cin>>s;
		for(char i:s)
		{
			if(i=='N') ca++;
			else cb++;
		}
		a[i].fir=cb,a[i].sec=ca;
	}
	// for(int i=1;i<=n;i++) printf("%d %d\n",a[i].fir,a[i].sec);
	int l=0,r=N,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	print(ans);
	return 0;
}