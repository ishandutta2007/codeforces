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
#define N 1205
int a[N],bel[N],id[N],fa[N],dgr[N],vis[N],n,m;
int st[N],tp;
signed main()
{
	cin>>n;
	for(int i=1;i<=n*3;i++) a[read()]=1;
	for(int i=1;i<=n*6;i++)
	{
		st[++tp]=i;
		if(tp==1||a[i]!=a[st[tp-1]])
		{
			id[i]=++m,fa[m]=id[st[tp-1]],bel[m]=a[i]&1;
		}
		else
		{
			id[i]=id[st[tp-1]];
			if(tp>=3&&a[st[tp-2]]==a[st[tp-1]]) tp-=3;
		}
	}
	for(int i=1;i<=m;i++) dgr[fa[i]]++;
	assert(!tp);
	for(int i=1;i<=n*2;i++)
	{
		int pos=0;
		for(int j=1;j<=m;j++)
		{
			if(vis[j]||dgr[j]||(i&1)!=bel[j]) continue;
			pos=j;
			if(fa[j]) break;
		}
		if(!pos)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[j]||dgr[j]||(i&1)!=bel[j]) continue;
				pos=j;
			}
		}
		vis[pos]=1,dgr[fa[pos]]--;
		for(int j=1;j<=n*6;j++) if(id[j]==pos) printf("%d ",j);
		cout<<"\n";
	}
	return 0;
}