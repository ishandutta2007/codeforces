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
int p[N],vis[N],n;
vector<pii> ans;
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) p[i]=read();
	vector<vector<int>> v;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(p[i]==i) vis[i]=1;
		else
		{
			vector<int> r; int cur=i;
			while(!vis[cur]) vis[cur]=1,r.pb(cur),cur=p[cur];
			v.pb(r);
		}
	}
	while(v.size()>=2)
	{
		vector<int> a=v.back(); v.pop_back();
		vector<int> b=v.back(); v.pop_back();
		ans.eb(a[0],b[0]);
		for(int i=1;i<(int)a.size();i++) ans.eb(a[i],b[0]);
		for(int i=1;i<(int)b.size();i++) ans.eb(a[0],b[i]);
		ans.eb(a[0],b[0]);
	}
	if(!v.empty())
	{
		vector<int> a=v[0];
		if(a.size()>=3)
		{
			ans.eb(a.back(),a[1]);
			for(int i=2;i+1<(int)a.size();i++) ans.eb(a[i],a.back());
			ans.eb(a.back(),a[0]),ans.eb(a[0],a[1]),ans.eb(a[1],a.back());
		}
		else
		{
			int pos; for(int i=1;i<=n;i++) if(a[0]!=i&&a[1]!=i) {pos=i; break;}
			ans.eb(a[0],pos),ans.eb(a[1],pos),ans.eb(a[0],pos);
		}
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans) printf("%d %d\n",x,y);
	return 0;
}