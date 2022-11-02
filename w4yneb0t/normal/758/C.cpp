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
in n,m,rk;
in q(in x, in y){
  in k=rk;
  if(n==1){
    in c=k/m;
    k%=m;
    if(k>y)
      ++c;
    return c;
  }
  in tr=2*(n-1)*m;
  in c=k/tr;
  k%=tr;
  if(x!=0 && x!=n-1)
    c*=2;
  forn(i,n-1){
    if(i==x && k>y)
      ++c;
    k-=m;
  }
  for(in i=n-1;i>0;--i){
    if(i==x && k>y)
      ++c;
    k-=m;
  }
  return c;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in x,y;
  cin>>n>>m>>rk>>x>>y;
  --x;
  --y;
  in mx=q(0,0);
  if(n>1){
    mx=max(mx,q(1,0));
    mx=max(mx,q(n-2,0));
  }
  in mn=q(0,m-1);
  if(n>1){
    mn=min(mn,q(n-1,m-1));
  }
  cout<<mx<<" "<<mn<<" "<<q(x,y)<<endl;
  return 0;
}