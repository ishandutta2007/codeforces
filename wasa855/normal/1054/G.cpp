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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 2005
int cnt[N][N],siz[N],vis[N];
bitset<N> a[N];
int fa[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int n,m;
int tag,CNT;
void work()
{
	CNT++;
	if(tag&&CNT==8)
	{
		cin>>n>>m;
		printf("%d %d\n",n,m);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++) putchar(rdchar());
			cout<<"\n";
		}
		return ;
	}
	cin>>n>>m;
	// for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char ch=rdchar();
			if(ch=='1') a[j][i]=1,siz[i]++;
		}
	}
	if(tag) return ;
	for(int i=1;i<=m;i++)
	{
		if(siz[i]==1)
		{
			for(int j=1;j<=n;j++) if(a[j][i]) a[j][i]=0;
			siz[i]=0;
		}
	}
	vector<pii> ans; queue<pii> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			bitset<N> r=a[i]&a[j];
			cnt[i][j]=(r^a[i]).count();
			if(!cnt[i][j]) q.emplace(i,j);
		}
	}
	while(!q.empty())
	{
		auto [u,v]=q.front(); q.pop();
		// u=find(u),v=find(v);
		// if(find(u)==find(v)) continue;
		if(vis[u]||vis[v]) continue;
		vis[u]=1;
		ans.eb(u,v); fa[find(u)]=find(v);
		for(int j=1;j<=m;j++) if(a[u][j])
		{
			siz[j]--; a[u][j]=0;
			if(siz[j]==1)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i][j])
					{
						a[i][j]=0;
						for(int k=1;k<=n;k++) if(k!=i)
						{
							cnt[i][k]--;
							if(!cnt[i][k]) q.emplace(i,k);
						}
					}
				}
				siz[j]=0;
			}
		}
	}
	if((int)ans.size()==n-1)
	{
		cout<<"YES\n";
		for(auto [u,v]:ans) printf("%d %d\n",u,v);
	}
	else cout<<"NO\n";
	for(int i=1;i<=n;i++) a[i].reset();
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=m;i++) siz[i]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cnt[i][j]=0;
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}