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
	int n,m,d;
	cin>>n>>m>>d;
	UnionFind uf(n+1);
	vector<pint>v(m);
	int cnt=0;
	rep(i,m){
		cin>>v[i].first>>v[i].second;
		if(v[i].first>v[i].second)swap(v[i].first,v[i].second);
		if(v[i].first==1||v[i].second==1)++cnt;
		else uf.unite(v[i].first, v[i].second);
	}
	if(cnt<d){
		cout<<"NO"<<endl;
		return 0;
	}
	UnionFind uf2(n+1);
	int cnt2=0;
	vector<pint> ans;
	rep(i,m){
		if(v[i].first==1){
			if(uf.unite(v[i].first, v[i].second)){
				uf2.unite(v[i].first,v[i].second);
				++cnt2;
				ans.push_back(v[i]);
			}
		}
	}
	if(cnt2>d){
		cout<<"NO"<<endl;
		return 0;
	}
	rep(i,m){
		if(cnt2==d)break;
		if(v[i].first==1){
			if(uf2.unite(v[i].first, v[i].second)){
				++cnt2;
				ans.push_back(v[i]);
				if(cnt2==d)break;
			}
		}
	}
	rep(i,m){
		if(v[i].first!=1&&uf2.unite(v[i].first, v[i].second)){
			ans.push_back(v[i]);
		}
	}
	assert(ans.size()==n-1);
	cout<<"YES"<<endl;
	for(auto p : ans){
		printf("%d %d\n",p.first,p.second);
	}
	return 0;
}