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
void imp(){
  cout<<-1<<endl;
  exit(0);
}
const in inf=1e18;
in bst=inf;
in totc=0;
in hv=0;
void ad(VI& v, in& n){
  assert(n<sz(v));
  totc+=v[n++];
  ++hv;
}
void rm(VI& v, in& n){
  assert(n>0);
  totc-=v[--n];
  --hv;
}
VI both,a,b,none;
in nboth=0;
in na=0;
in nb=0;
in nnone=0;
void adcp(){
  in s=inf;
  if(na<sz(a))
    s=min(s,a[na]);
  if(nb<sz(b))
    s=min(s,b[nb]);
  if(nnone<sz(none))
    s=min(s,none[nnone]);
  assert(s!=inf);
  if(na<sz(a) && s==a[na]){
    ad(a,na);
    return;
  }
  if(nb<sz(b) && s==b[nb]){
    ad(b,nb);
    return;
  }
  assert(nnone<sz(none) && s==none[nnone]);
  ad(none,nnone);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,k;
  cin>>n>>m>>k;
  VI c(n);
  forn(i,n)
    cin>>c[i];
  VI la(n);
  VI lb(n);
  in ta;
  cin>>ta;
  in tp;
  forn(z,ta){
    cin>>tp;
    --tp;
    la[tp]=1;
  }
  cin>>ta;
  forn(z,ta){
    cin>>tp;
    --tp;
    lb[tp]=1;
  }
  forn(i,n){
    if(la[i] && lb[i]){
      both.PB(c[i]);
      continue;
    }
    if(la[i]){
      a.PB(c[i]);
      continue;
    }
    if(lb[i]){
      b.PB(c[i]);
      continue;
    }
    none.PB(c[i]);
  }
  sort(all(both));
  sort(all(a));
  sort(all(b));
  sort(all(none));
  in mnc=0;
  if(m<k)
    imp();
  mnc=max(mnc,k-sz(a));
  mnc=max(mnc,k-sz(b));
  mnc=max(mnc,m-sz(a)-sz(b)-sz(none));
  mnc=max(mnc,2*k-m);
  in mxc=sz(both);
  mxc=min(mxc,m);
  if(mnc>mxc)
    imp();
  while(nboth<mnc){
    ad(both,nboth);
  }
  forn(z,k-mnc){
    ad(a,na);
  }
  forn(z,k-mnc){
    ad(b,nb);
  }
  assert(hv<=m);
  while(hv<m){
    adcp();
  }
  bst=min(bst,totc);
  for(in tk=mnc+1;tk<=mxc;++tk){
    ad(both,nboth);
    if(na>0)
      rm(a,na);
    if(nb>0)
      rm(b,nb);
    if(nnone>0)
      rm(none,nnone);
    assert(hv<=m);
    while(hv<m)
      adcp();
    bst=min(bst,totc);
  }
  assert(bst!=inf);
  cout<<bst<<endl;
  return 0;
}