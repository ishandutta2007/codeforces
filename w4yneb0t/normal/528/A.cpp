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
void ad(map<in,in,greater<in> >& mx, in vl, in fc){
  mx[vl]+=fc;
  if(mx[vl]==0)
    mx.erase(vl);
}
void mkc(set<in>& s, map<in,in,greater<in> >& mx, in loc){
  set<in>::iterator it=s.insert(loc).first;
  in t1,t2;
  --it;
  t1=*it;
  ++it;++it;
  t2=*it;
  ad(mx,t2-t1,-1);
  ad(mx,t2-loc,1);
  ad(mx,loc-t1,1);
}
in w,h,n;
set<in> hct,wct;
map<in,in,greater<in> > wmx,hmx;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>w>>h>>n;
  ad(hmx,h,1);
  ad(wmx,w,1);
  hct.insert(0);
  hct.insert(h);
  wct.insert(0);
  wct.insert(w);
  char typ;
  in loc;
  forn(z,n){
    cin>>typ>>loc;
    if(typ=='H')
      mkc(hct,hmx,loc);
    else
      mkc(wct,wmx,loc);
    cout<<hmx.begin()->first*wmx.begin()->first<<endl;
  }
  return 0;
}