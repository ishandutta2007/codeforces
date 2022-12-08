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
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


struct StronglyConnectedComponents{
	vector<int> used,cmp,vs;
	vector<vector<int>> v,rv;
	StronglyConnectedComponents(int n):used(n),cmp(n,-1),v(n),rv(n){}

	void add_edge(int x,int y){
		v[x].push_back(y);
		rv[y].push_back(x);
	}
	void dfs(int x){
		used[x]=true;
		for(auto to:v[x])if(!used[to])dfs(to);
		vs.push_back(x);
	}

	void rdfs(int x,int k){
		cmp[x]=k;
		for(auto to:rv[x])if(cmp[to]==-1)rdfs(to,k);
	}

	int scc(){
		rep(i,used.size())if(!used[i])dfs(i);
		reverse(vs.begin(),vs.end());
		int k=0;
		for(auto x:vs)if(cmp[x]==-1)rdfs(x,k++);
		return k;
	}
	void build(vector<vector<int>> &g){
		int k=scc();
		g.resize(k);
		set<pair<int,int>> used;
		rep(i,v.size()){
			for(auto& to:v[i]){
				int x=cmp[i],y=cmp[to];
				if(x==y||used.count({x,y}))continue;
				g[x].push_back(y);
				used.emplace(x,y);
			}
		}
	}
};

int main(){
	int n, m, h;
	cin>>n>>m>>h;
	StronglyConnectedComponents scc(n);
	int a[n];
	rep(i,n)cin>>a[i];
	rep(i,m){
		int x,y;
		cin>>x>>y;
		--x;--y;
		if((a[x]+1)%h == a[y]){
			scc.add_edge(x, y);
		}
		if(a[x]==(a[y]+1)%h){
			scc.add_edge(y, x);
		}
	}
	vector<vector<int>> g;
	scc.build(g);
	int k = g.size();
	vector<int> cnt(k);
	rep(i,n)cnt[scc.cmp[i]]++;
	int idx = -1, mi = inf;
	rep(i,k){
		if(g[i].empty()&&cnt[i]<mi){
			idx = i;
			mi = cnt[idx];
		}
	}
	cout<<mi<<endl;
	rep(i,n){
		if(scc.cmp[i]==idx)cout<<i+1<<" ";
	}
	cout<<endl;
	return 0;
}