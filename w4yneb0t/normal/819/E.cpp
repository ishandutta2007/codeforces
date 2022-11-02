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
VVI cycs;
VI tp;
void adso(const VI& id, VVI c){
  forv(i,c){
    tp.clear();
    forv(j,c[i])
      tp.PB(id[c[i][j]]);
    cycs.PB(tp);
  }
}
void slv(VI id){
  in n=sz(id);
  assert(n>=3);
  if(n==3){
    adso(id,{{0,1,2},{0,1,2}});
    return;
  }
  if(n==4){
    adso(id,{{0,1,2},{1,2,3},{2,3,0},{3,0,1}});
    return;
  }
  if(n==5){
    adso(id,{{4,3,1},{2,0,4},{3,4,1,2},{3,2,1,0},{3,1,0},{2,0,4}});
    return;
  }
  VI bs;
  forn(z,3){
    bs.PB(id.back());
    id.pop_back();
  }
  adso(bs,{{0,1,2}});
  if(sz(id)%2==0){
    adso(bs,{{0,1,2}});
  }
  else{
    bs.PB(id.back());
    adso(bs,{{0,1,3},{1,2,3},{0,2,3}});
    bs.pop_back();
  }
  VI cr;
  for(in i=0;i+1<sz(id);i+=2){
    cr=bs;
    cr.PB(id[i]);
    cr.PB(id[i+1]);
    for(in j=0;j<3;++j){
      adso(cr,{{j,3,(j+1)%3,4}});
    }
  }
  slv(id);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  VI inds;
  forn(i,n)
    inds.PB(i+1);
  slv(inds);
  cout<<sz(cycs)<<"\n";
  forv(i,cycs){
    cout<<sz(cycs[i])<<" ";
    forv(j,cycs[i])
      cout<<cycs[i][j]<<" ";
    cout<<"\n";
  }
  return 0;
}