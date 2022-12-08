#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


struct edge{int to;ll cap;int rev;};
struct Dinic{
private:
	int n;
	vector<vector<edge>> v;
	vector<int> dist,iter;
public:
	Dinic(int sz):n(sz),v(sz),dist(sz),iter(sz){}
	
	void addedge(int from,int to,ll cap){
		int x=v[to].size(),y=v[from].size();
		v[from].push_back({to,cap,x});
		v[to].push_back({from,0,y});
	}
	
	void bfs(int s){
		fill(dist.begin(),dist.end(),-1);
		queue<int> q;
		dist[s]=0;
		q.push(s);
		while(q.size()){
			int x=q.front();q.pop();
			rep(i,v[x].size()){
				edge &e=v[x][i];
				if(e.cap>0&&dist[e.to]<0){
					dist[e.to]=dist[x]+1;
					q.push(e.to);
				}
			}
		}
	}
	
	ll dfs(int x,int t,ll f){
		if(x==t)return f;
		for(int& i=iter[x];i<(int)v[x].size();++i){
			edge& e=v[x][i];
			if(e.cap>0&&dist[x]<dist[e.to]){
				ll d=dfs(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					v[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}

	ll max_flow(int s,int t){
		ll flow=0;
		while(1){
			bfs(s);
			if(dist[t]<0)return flow;
			fill(iter.begin(),iter.end(),0);
			int f;
			while((f=dfs(s,t,1LL<<62))>0)flow+=f;
		}
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	Dinic dn(m+n+2);
	int s=m+n, g=m+n+1;
	ll ret=0;
	rep(i,n){
		int x;cin>>x;
		dn.addedge(m+i,g,x);
	}
	rep(i,m){
		int x,y,z;
		cin>>x>>y>>z;
		--x;--y;
		dn.addedge(s, i, z);
		dn.addedge(i, m+x, longinf);
		dn.addedge(i, m+y, longinf);
		ret+=z;
	}
	cout<<ret-dn.max_flow(s, g)<<endl;
	return 0;
}