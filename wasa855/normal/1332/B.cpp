#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1005
int a[N];
bool vis[N];
int ans[N];
int p[N];int cnt=0;
bool prime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) vis[i]=0;
	int res=0,_cnt=0;
	while(res<n)
	{
		_cnt++;
		int maxn=0,maxp=0;
		for(int i=1;i<=cnt;i++)
		{
			int res=0;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]) continue;
				if(a[j]%p[i]==0) res++;
			}
			if(res>maxp) maxp=res,maxn=p[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(a[i]%maxn==0) vis[i]=1,ans[i]=_cnt,res++;
		}
	}
	printf("%d\n",_cnt);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]); cout<<"\n";
}
signed main()
{
	for(int i=2;i<=33;i++)
	{
		if(prime(i)) p[++cnt]=i;
	}
	// cout<<cnt<<endl;
	int T=read();
	while(T--) work();
	return 0;
}