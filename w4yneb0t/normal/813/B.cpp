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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in x,y,l,r;
  cin>>x>>y>>l>>r;
  VI px={1};
  while(px.back()<=r/x){
    px.PB(px.back()*x);
  }
  VI py={1};
  while(py.back()<=r/y){
    py.PB(py.back()*y);
  }
  VI bd;
  bd.PB(l-1);
  bd.PB(r+1);
  forv(i,px){
    forv(j,py){
      bd.PB(px[i]+py[j]);
    }
  }
  sort(all(bd));
  in i=0;
  while(bd[i]<l-1)
    ++i;
  ++i;
  in bst=0;
  while(i<sz(bd) && bd[i]<=r+1){
    bst=max(bst,bd[i]-bd[i-1]-1);
    ++i;
  }
  cout<<bst<<endl;
  return 0;
}