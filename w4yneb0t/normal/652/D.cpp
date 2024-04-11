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
struct sg{
  in l,r,id;
  sg(in a=0, in b=0, in c=0){
    l=a;
    r=b;
    id=c;
  }
  bool operator<(const sg cp)const{
    if(l==cp.l)
      assert(id==cp.id);
    return l<cp.l;
  }
};
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
fenw mtr;
vector<sg> sgs;
VI vls;
map<in,in> dcd;
VI res;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  sgs.resize(n);
  forn(i,n){
    cin>>sgs[i].l>>sgs[i].r;
    vls.PB(sgs[i].l);
    vls.PB(sgs[i].r);
    sgs[i].id=i;
  }
  sort(all(vls));
  forv(i,vls)
    dcd[vls[i]]=i;
  forv(i,sgs){
    sgs[i].l=dcd[sgs[i].l];
    sgs[i].r=dcd[sgs[i].r];
  }
  sort(all(sgs));
  mtr.ini(sz(dcd)+3);
  res.resize(n);
  for(in i=sz(sgs)-1;i>=0;--i){
    res[sgs[i].id]=mtr.sm(sgs[i].r);
    mtr.ad(sgs[i].r,1);
  }
  forv(i,res)
    cout<<res[i]<<"\n";
  return 0;
}