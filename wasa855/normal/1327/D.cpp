#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
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
#define N 200005
int p[N],a[N],vis[N];
int solve(vector<int> v,int x)
{
	bool ok=0;
	// int gap=v.size()/x;
	for(int i=0;i<x;i++)
	{
		bool cur=1;
		for(int j=i+x;j<v.size();j+=x)
		{
			if(a[v[j]]!=a[v[j-x]]) cur=0;
		}
		if(cur) ok=1;
	}
	// printf("%d %d %d\n",v.size(),x,ok);
	if(ok) return x;
	else return INF;
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) vis[i]=0;
	int ans=INF;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vector<int> v;
			int cur=i;
			while(!vis[cur]) vis[cur]=1,v.pb(cur),cur=p[cur];
			int s=v.size();
			// cout<<"**"<<s<<endl;
			for(int i=1;i*i<=s;i++)
			{
				if(s%i==0)
				{
					ans=min(ans,solve(v,i));
					ans=min(ans,solve(v,s/i));
				}
			}
		}
	}
	printf("%d\n",ans);
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}