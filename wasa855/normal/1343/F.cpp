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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 205
set<int> a[N],b[N];
int be[N],ed[N],vis[N];
int ans[N],n;
bool ok()
{
	for(int i=2;i<=n;i++)
	{
		if(ed[i]-be[i]+1!=(int)b[i].size()) return 0;
	}
	return 1;
}
int solve(int x)
{
	ans[1]=x;
	for(int i=2;i<=n;i++) a[i]=b[i];
	for(int i=2;i<=n;i++) vis[i]=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i].find(x)!=a[i].end())
		{
			if(!vis[i]) vis[i]=1,be[i]=1;
			a[i].erase(x);
		}
	}
	for(int i=2;i<=n;i++)
	{
		int id=0;
		for(int j=2;j<=n;j++)
		{
			if(a[j].size()==1)
			{
				if(!id) id=j;
				else return 0;
			}
		}
		if(!id) return 0;
		ans[i]=*a[id].begin(); ed[id]=i;
		for(int j=2;j<=n;j++)
		{
			if(a[j].find(ans[i])!=a[j].end())
			{
				if(!vis[j]) vis[j]=1,be[j]=i;
				a[j].erase(ans[i]);
			}
		}
	}
	for(int i=2;i<=n;i++) if(!a[i].empty()) return 0;
	// for(int i=1;i<=n;i++) printf("%d ",ans[i]); cout<<"\n"; 
	// for(int i=2;i<=n;i++) printf("%d %d\n",be[i],ed[i]);
	return ok();
}
void work()
{
	n=read();
	for(int i=2;i<=n;i++) b[i].clear();
	for(int i=2;i<=n;i++)
	{
		int m=read();
		while(m--) b[i].insert(read());
	}
	for(int i=1;i<=n;i++)
	{
		if(solve(i))
		{
			for(int j=1;j<=n;j++) printf("%d ",ans[j]); cout<<"\n";
			return ;
		}
	}
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}