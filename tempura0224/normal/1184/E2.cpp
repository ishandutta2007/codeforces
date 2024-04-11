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



struct ppUF{
   vector<int> par,ti;
   vector<vector<pair<int,int>>> his;
   ppUF(int n):ti(n,inf+1),par(n,-1),his(n){
	   for(auto &vs:his)vs.emplace_back(-1,-1);
   }
   int find(int t,int x){
	   if(ti[x]>t)return x;
	   return find(t,par[x]);
   }

   bool unite(int t,int x,int y){
	   x=find(t,x);y=find(t,y);
	   if(x==y)return false;
	   if(par[x]>par[y])swap(x,y);
	   par[x]+=par[y];
	   his[x].emplace_back(t,par[x]);
	   par[y]=x;
	   ti[y]=t;
	   return true;
   }

   bool same(int t,int x,int y){
	   return find(t,x)==find(t,y);
   }
   int time(int x,int y){
	   if(!same(inf,x,y))return -1;
	   int ok=inf,ng=-1,mid=0;
	   while(ok-ng>1){
		   mid=(ok+ng)/2;
		   if(same(mid,x,y))ok=mid;
		   else ng=mid;
	   }
	   return ok;
   }

   int size(int t,int x){
	   x = find(t,x);
	   return -prev(lower_bound(his[x].begin(),his[x].end(),pair<int,int>(t,0)))->second;
   }
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(m),b(m),c(m);
	rep(i,m){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	vector<int> ord(m);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int s,int t){
		return c[s]<c[t];
	});
	ppUF uf(n+1);
	vector<ll> ans(m,-1);
	for(auto i : ord){
		if(!uf.same(inf, a[i], b[i]))uf.unite(c[i],a[i],b[i]);
		else {
			ans[i]=uf.time(a[i],b[i]);
		}
	}
	rep(i,m){
		if(ans[i]==-1)continue;
		printf("%lld\n",ans[i]);
	}
	return 0;
}