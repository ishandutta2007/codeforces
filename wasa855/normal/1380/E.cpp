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
typedef pair<int,int> pii;
#define N 200005
int fa[N],a[N],n,m,siz[N];
vector<int> v[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) v[a[i]].pb(i);
	for(int i=1;i<=m;i++) fa[i]=i,siz[i]=1;
	int ans=n-1;
	for(int i=1;i<n;i++) ans-=a[i]==a[i+1];
	printf("%d\n",ans);
	for(int _=1;_<m;_++)
	{
		int x=find(read()),y=find(read());
		if(siz[x]>siz[y]) swap(x,y);
		fa[x]=y,siz[y]+=siz[x];
		for(int i:v[x])
		{
			ans+=a[i]==a[i+1];
			ans+=a[i]==a[i-1];
			a[i]=y;
			ans-=a[i]==a[i+1];
			ans-=a[i]==a[i-1];
			v[y].pb(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}