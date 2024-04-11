#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
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
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 100005
int u[N],v[N],dgr[N];
vector<int> G[N];
int ans[N],cnt=0;
signed main()
{
	int n=read();
	for(int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read();
		dgr[u[i]]++,dgr[v[i]]++;
		G[u[i]].pb(i),G[v[i]].pb(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(G[i].size()>=3)
		{
			cnt=3;
			ans[G[i][0]]=1;
			ans[G[i][1]]=2;
			ans[G[i][2]]=3;
			break;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(ans[i]) printf("%d\n",ans[i]-1);
		else printf("%d\n",cnt++);
	}
	return 0;
}