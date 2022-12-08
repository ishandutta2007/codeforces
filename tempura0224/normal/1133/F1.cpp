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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
	   if(par[x]<0)return x;
	   return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
	   x=find(x);
	   y=find(y);
	   if(x==y)return false;
	   if(par[x]>par[y]){
		   par[y]+=par[x];
		   par[x]=y;
	   }
	   else{
		   par[x]+=par[y];
		   par[y]=x;
	   }
	   return true;
   }

   bool same(int x,int y){
	   return find(x)==find(y);
   }
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> cnt(n+1);
	vector<pair<int,int>> v(m);
	rep(i,m){
		int x,y;
		cin>>x>>y;
		++cnt[x];
		++cnt[y];
		v[i]={x,y};
	}
	int ans=max_element(cnt.begin(), cnt.end())-cnt.begin();
	vector<pint> ret;
	UnionFind uf(n+1);
	rep(i,m){
		if(v[i].first==ans||v[i].second==ans){
			ret.push_back(v[i]);
			uf.unite(v[i].first,v[i].second);
		}
	}
	rep(i,m){
		if(uf.unite(v[i].first, v[i].second))ret.push_back(v[i]);
	}
	assert(ret.size()==n-1);
	for(auto p : ret){
		printf("%d %d\n",p.first,p.second);
	}
	return 0;
}