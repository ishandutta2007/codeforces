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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

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
   int n;
   cin>>n;
   int a[n];
   rep(i,n)cin>>a[i];
   UnionFind uf(n);
   int par[20][n];
   rep(i,n)cin>>par[0][i];
   rep(i,n)--par[0][i];
   rep(i,n)uf.unite(par[0][i], par[0][par[0][i]]);
   rep(i,19)rep(j,n)par[i+1][j]=par[i][par[i][j]];   
   int c[n];
   rep(i,n)c[i]=inf;
   rep(i,n){
       int idx=uf.find(par[19][i]);
       c[idx]=min(c[idx],a[par[19][i]]);
   }
   int ans=0;
   rep(i,n)if(c[i]!=inf)ans+=c[i];
   cout<<ans<<endl;
   return 0;
}