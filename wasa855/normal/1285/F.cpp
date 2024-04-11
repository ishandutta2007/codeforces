#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
int mu[N];
bool prim[N];
int p[N],cnt;
vector<int> v[N];
void init(int n)
{
	mu[1]=1,prim[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!prim[i])
		{
			p[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(p[j]*i>n) break;
			mu[p[j]*i]=-mu[i];
			prim[p[j]*i]=1;
			if(i%p[j]==0)
			{
				mu[i*p[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i) v[j].pb(i);
	}
}
bool vis[N];
int c[N],t[N];
int calc(int x)
{
	int ans=0;
	for(int i:v[x]) ans+=mu[i]*c[i];
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int u=read();
		vis[u]=1;
		if(u>maxn) maxn=u;
	}
	init(maxn);
	int ans=maxn;
	for(int g=1;g<=maxn;g++)
	{
		int cur=0;
		for(int i=maxn/g;i>=1;i--)
		{
			if(!vis[i*g]) continue;
			while(calc(i))
			{
				if(i*g*t[cur]>ans) ans=i*g*t[cur];
				for(int j:v[t[cur]]) c[j]--;
				cur--;
			}
			t[++cur]=i;
			for(int j:v[i]) c[j]++;
		}
		while(cur)
		{
			for(int i:v[t[cur]]) c[i]--;
			cur--;
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}