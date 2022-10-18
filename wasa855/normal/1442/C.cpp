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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 200005
vector<int> G[2][N];
struct Node
{
	int id,cnt,dis;
	bool operator < (const Node &x) const
	{
		if(cnt!=x.cnt) return cnt>x.cnt;
		return dis>x.dis;
	}
	bool operator == (const Node &x) const {return id==x.id&&cnt==x.cnt&&dis==x.dis;}
};
vector<Node> v[N];
priority_queue<Node> q;
int n,m;
bool chk_in(vector<Node> &x,Node &y)
{
	for(Node i:x) if(i==y) return 1;
	return 0;
}
const int B=20;
void upd(vector<Node> &x,Node y)
{
	// printf("%d %d %d\n",y.id,y.cnt,y.dis);
	if(x.empty()) {x.pb(y); q.push(y); return ;}
	if(y.cnt>x[0].cnt+B) return ;
	for(int i=0;i<(int)x.size();i++)
	{
		if(x[i].cnt==y.cnt)
		{
			if(y.dis<x[i].dis) x[i].dis=y.dis,q.push(y);
			return ;
		}
	}
	for(int i=0;i<(int)x.size();i++)
	{
		if(x[i].cnt>y.cnt)
		{
			x.pb(x.back());
			for(int j=x.size()-2;j>i;j--) x[j]=x[j-1];
			x[i]=y;
			q.push(y);
			if(x.size()>B) x.pop_back();
			return ;
		}
	}
	if(x.size()<B) x.pb(y),q.push(y);
}
bool cmp(Node x,Node y)
{
	if(x.cnt<=20&&y.cnt<=20) return (1<<x.cnt)+x.dis<(1<<y.cnt)+y.dis;
	else return x.cnt<y.cnt;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[0][u].pb(v),G[1][v].pb(u);
	}
	v[1].pb((Node){1,0,0});
	q.push((Node){1,0,0});
	while(!q.empty())
	{
		Node U=q.top(); q.pop();
		if(!chk_in(v[U.id],U)) continue;
		int r=U.cnt&1,u=U.id;
		for(int _v:G[r][u])
		{
			Node V=(Node){_v,U.cnt,U.dis+1};
			upd(v[_v],V);
		}
		for(int _v:G[r^1][u])
		{
			Node V=(Node){_v,U.cnt+1,U.dis+1};
			// printf("%d %d\n",u,_v);
			upd(v[_v],V);
		}
	}
	sort(v[n].begin(),v[n].end(),cmp);
	cout<<(qpow(2,v[n][0].cnt)-1+v[n][0].dis)%mod<<endl;
	return 0;
}