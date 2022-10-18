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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 100005
vector<int> v[65];
int a[N],n,b[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read(),v[a[i]+30].pb(i);
	int ans=-inf;
	for(int i=-30;i<=30;i++)
	{
		for(int j:v[i+30]) b[j]=1;
		int cur=0;
		for(int j=1;j<=n;j++)
		{
			if(!b[j]) {cur=0; continue;}
			cur+=a[j];
			if(cur-i>ans) ans=cur-i;
			if(cur<0) cur=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}