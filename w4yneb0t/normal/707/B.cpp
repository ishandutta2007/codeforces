#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI u,v,l;
VI hs;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  const in inf=1e18;
  in bst=inf;
  in n,m,k;
  cin>>n>>m>>k;
  u=v=l=VI(m);
  forn(i,m)
    cin>>u[i]>>v[i]>>l[i];
  hs.resize(n+1,0);
  in t;
  forn(i,k){
    cin>>t;
    hs[t]=1;
  }
  forv(i,u){
    if(!hs[u[i]])
      swap(u[i],v[i]);
    if(!hs[u[i]])
      continue;
    if(hs[v[i]])
      continue;
    bst=min(bst,l[i]);
  }
  if(bst==inf)
    cout<<-1<<endl;
  else
    cout<<bst<<endl;
  return 0;
}