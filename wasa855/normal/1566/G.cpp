#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
map<int,int> mp[N];
struct Edge
{
	int u,v,w;
	bool operator < (const Edge &x) const
	{
		if(w!=x.w) return w<x.w;
		else if(u!=x.u) return u<x.u;
		else return v<x.v;
	}
};
map<Edge,int> qwq;
set<Edge> eg[N];
set<Edge> tot;
int istest=0;
int dgr[N];
void del(int u)
{
	int cnt=0;
	for(auto i:eg[u])
	{
		cnt++;
		if(cnt==4) break;
		qwq[i]--;
		if(qwq[i]==1) dgr[i.u]--,dgr[i.v]--,tot.erase(i);
	}
}
void ins(int u)
{
	int cnt=0;
	for(auto i:eg[u])
	{
		cnt++;
		if(cnt==4) break;
		if(qwq[i]==1) tot.insert(i);
		qwq[i]++;
	}
}
void insert(int u,int v,int w)
{
	del(u),del(v); mp[u][v]=w;
	eg[u].insert((Edge){u,v,w});
	eg[v].insert((Edge){u,v,w});
	ins(u),ins(v);
}
void erase(int u,int v,int w)
{
	del(u),del(v); mp[u][v]=0;
	eg[u].erase((Edge){u,v,w});
	eg[v].erase((Edge){u,v,w});
	ins(u),ins(v);
}
bool same(Edge x,Edge y) {return x.u==y.u||x.v==y.u||x.u==y.v||x.v==y.v;}
bool three(Edge x,Edge y,Edge z)
{
	set<int> s;
	s.insert(x.u),s.insert(x.v);
	s.insert(y.u),s.insert(y.v);
	s.insert(z.u),s.insert(z.v);
	return s.size()==3;
}
void query()
{
	vector<Edge> tmp;
	for(int i=0;i<10;i++)
	{
		if(tot.empty()) break;
		tmp.pb(*tot.begin());
		tot.erase(tot.begin());
	}
	// for(int i=0;i<4;i++) printf("%d %d %d\n",tmp[i].u,tmp[i].v,tmp[i].w);
	int ans;
	if(three(tmp[0],tmp[1],tmp[2])) ans=tmp[0].w+tmp[1].w+tmp[3].w;
	else ans=tmp[0].w+tmp[1].w+tmp[2].w;
	for(int i=0;i<(int)tmp.size();i++) for(int j=i+1;j<(int)tmp.size();j++)
	{
		if(!same(tmp[i],tmp[j])) ans=min(ans,tmp[i].w+tmp[j].w);
	}
	printf("%lld\n",ans);
	for(int i=0;i<(int)tmp.size();i++) tot.insert(tmp[i]);
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		if(u>v) swap(u,v);
		insert(u,v,w);
	}
	// if(n==100000) istest=1;
	query();
	int Q=read();
	for(int i=1;i<=Q;i++)
	{
		int op=read(),u=read(),v=read();
		if(u>v) swap(u,v);
		if(op==0) erase(u,v,mp[u][v]);
		else
		{
			int w=read();
			insert(u,v,w);
		}
		query();
	}
	return 0;
}