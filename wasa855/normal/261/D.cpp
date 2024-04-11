#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
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
int t[N];
int a[N];
bool vis[N];
int k,n,maxb,T;
int lowbit(int u){return u&(-u);}
void update(int u,int d)
{
	while(u<=maxb)
	{
		if(d>t[u]) t[u]=d;
		u+=lowbit(u);
	}
}
int query(int u)
{
	int ans=0;
	while(u)
	{
		if(t[u]>ans) ans=t[u];
		u-=lowbit(u);
	}
	return ans;
}
signed main()
{
	cin>>k>>n>>maxb>>T;
	while(k--)
	{
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		int c=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(!vis[a[i]]) c++,vis[a[i]]=1;
		}
		if(T>=c)
		{
			printf("%d\n",c);
			continue;
		}
		int ans=0;
		for(int i=1;i<=T;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int R=query(a[j]-1)+1;
				if(R>ans) ans=R;
				update(a[j],R);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}