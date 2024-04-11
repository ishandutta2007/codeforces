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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 200005
const int S=455;
vector<int> a[N],v[N];
vector<int> pos;
int tmp[N],vis[N];
int n,cnt;
void work()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i].clear();
	pos.clear(); cnt=0;
	for(int i=1;i<=n;i++)
	{
		int s=read(); a[i].resize(s);
		for(int j=0;j<s;j++) a[i][j]=read(),tmp[++cnt]=a[i][j];
		if(s>=S) pos.pb(i);
	}
	sort(tmp+1,tmp+cnt+1); int T=unique(tmp+1,tmp+cnt+1)-tmp-1;
	for(int i=1;i<=cnt;i++) v[i].clear();
	for(int i=1;i<=n;i++) for(int j=0;j<(int)a[i].size();j++) a[i][j]=lower_bound(tmp+1,tmp+T+1,a[i][j])-tmp;
	// for(int i=1;i<=n;i++) print(a[i]);
	// for(int i=1;i<=cnt;i++) printf("%d%c",vis[i]," \n"[i==cnt]);
	for(int cur:pos)
	{
		for(int j:a[cur]) vis[j]=1;
		int ay=0;
		for(int i=1;i<=n;i++)
		{
			if(cur==i) continue;
			int cnt=0;
			for(int j:a[i]) cnt+=vis[j];
			if(cnt>=2) ay=i;
		}
		for(int j:a[cur]) vis[j]=0;
		if(ay) {printf("%d %d\n",cur,ay); return ;}
	}
	pos.clear();
	for(int i=1;i<=n;i++)
	{
		if((int)a[i].size()<S)
		{
			pos.pb(i);
			for(int j:a[i]) v[j].pb(i);
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		int ax=0,ay=0;
		for(int id:v[i])
		{
			for(int j:a[id])
			{
				if(j==i) continue;
				if(vis[j]) ax=vis[j],ay=id;
				vis[j]=id;
			}
		}
		for(int id:v[i])
		{
			for(int j:a[id])
			{
				if(j==i) continue;
				vis[j]=0;
			}
		}
		if(ax) {printf("%d %d\n",ax,ay); return ;}
	}
	printf("-1\n");
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}