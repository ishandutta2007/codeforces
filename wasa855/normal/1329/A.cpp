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
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 100005
int l[N];
int ans[N];
signed main()
{
	int n,m; cin>>n>>m;
	int sum=0;
	for(int i=1;i<=m;i++) l[i]=read(),sum+=l[i];
	if(sum<n)
	{
		cout<<"-1\n"; return 0;
	}
	if(m>n)
	{
		cout<<"-1\n"; return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(ans[i-1]+sum>=n) ans[i]=ans[i-1]+1;
		else
		{
			ans[i]=n-sum+1;
		}
		sum-=l[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]+l[i]-1>n)
		{
			cout<<"-1\n"; return 0;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}