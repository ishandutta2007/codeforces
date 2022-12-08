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
   int size(int x){
	   return -par[find(x)];
   }
};
int main(){
	int n,m;
	cin>>n>>m;
	int x,y,z;
	cin>>x>>y>>z;
	vector<int> a(m-1),b(m-1),c(m-1);
	rep(i,m-1){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	vector<int> ord(m-1);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int s,int t){
		return c[s]<c[t];
	});
	UnionFind uf(n+1);
	for(auto i : ord){
		uf.unite(a[i],b[i]);
		if(uf.same(x,y)){
			cout<<c[i]<<endl;
			return 0;
		}
	}
	cout<<1000000000<<endl;
	return 0;
}