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
#define int long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 300005
struct Node
{
	vector<int> v;
	int ch[2];
};
Node t[N*30];
int cnt=1;
void insert(int u,int id)
{
	int cur=1;
	for(int i=30;i>=0;i--)
	{
		int v=u>>i&1;
		if(!t[cur].ch[v]) t[cur].ch[v]=++cnt;
		cur=t[cur].ch[v];
		t[cur].v.pb(id);
	}
}
int a[N];
int ans[N][2];
pii get(vector<int> &a,vector<int> &b)
{
	int x=0,cnt=0;
	int i=0,j=0;
	while(i<(int)a.size()&&j<(int)b.size())
	{
		if(a[i]<b[j]) x+=cnt,i++;
		else cnt++,j++;
	}
	while(i<(int)a.size()) x+=cnt,i++;
	while(j<(int)b.size()) cnt++,j++;
	int y=0; cnt=0;
	i=0,j=0;
	while(i<(int)a.size()&&j<(int)b.size())
	{
		if(a[i]<b[j]) cnt++,i++;
		else y+=cnt,j++;
	}
	while(i<(int)a.size()) cnt++,i++;
	while(j<(int)b.size()) y+=cnt,j++;
	// print(a),print(b);
	// printf("%lld %lld\n\n",x,y);
	return mp(x,y);
}
void solve(int u,int dep)
{
	if(!t[u].ch[0]&&!t[u].ch[1]) return ;
	else if(!t[u].ch[0]) solve(t[u].ch[1],dep-1);
	else if(!t[u].ch[1]) solve(t[u].ch[0],dep-1);
	else
	{
		auto [x,y]=get(t[t[u].ch[0]].v,t[t[u].ch[1]].v);
		ans[dep][0]+=x,ans[dep][1]+=y;
		solve(t[u].ch[1],dep-1),solve(t[u].ch[0],dep-1);
	}
}
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		insert(a[i],i);
	}
	solve(1,30);
	int res=0,Ans=0;
	for(int i=0;i<=30;i++)
	{
		// printf("%lld - %lld %lld\n",i,ans[i][0],ans[i][1]);
		if(ans[i][1]<ans[i][0]) res+=ans[i][1],Ans|=1LL<<i;
		else res+=ans[i][0];
	}
	printf("%lld %lld\n",res,Ans);
	return 0;
}