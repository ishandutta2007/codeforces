#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}

signed main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int ans=0;
	for(int i=c;i<=d;i++)
	{
		int m=i-b+1;
		if(m>=a&&c-b+1>0)
		{
			int l=max(a,i-c) ;
			int d=c-i+l,e=c-i+min(b,m);
			// printf("%d %d %d\n",m,d,e);
			if(e>=d) ans+=(e+d)*(e-d+1)/2;
		}
		int L=b-max(m,a-1);
		// printf("%d %d\n",b,m);
		if(c-b+1>=0&&b>m) ans+=L*(c-b+1);
		// printf("%d\n",ans);
	}
	cout<<ans<<endl;
	return 0;
}