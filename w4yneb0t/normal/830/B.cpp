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
struct fenw{
  VI fw;
  in n;
  void ini(in pn){
    n=pn;
    fw.clear();
    fw.resize(n,0);
  }
  void ad(in l, in x){
    while(l<n){
      fw[l]+=x;
      l|=(l+1);
    }
  }
  in sm(in l){
    in r=0;
    while(l>=0){
      r+=fw[l];
      l&=(l+1);
      --l;
    }
    return r;
  }
};
fenw fw;
in sm=0;
VI srtl;
vector<set<in> > locs;
const in mx=100009;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  locs.resize(mx);
  in nxtu=-1;
  in a;
  in n;
  cin>>n;
  fw.ini(n);
  srtl.resize(n);
  forn(z,n){
    cin>>a;
    srtl[z]=a;
    fw.ad(z,1);
    locs[a].insert(z);
  }
  sort(all(srtl));
  in tf;
  set<in>::iterator it;
  forv(z,srtl){
    tf=srtl[z];
    it=locs[tf].lower_bound(nxtu);
    if(it==locs[tf].end()){
      sm+=fw.sm(n-1)-fw.sm(nxtu);
      it=locs[tf].begin();
      nxtu=-1;
    }
    sm+=fw.sm(*it)-fw.sm(nxtu);
    fw.ad(*it,-1);
    nxtu=*it;
    locs[tf].erase(it);
  }
  cout<<sm<<endl;
  return 0;
}