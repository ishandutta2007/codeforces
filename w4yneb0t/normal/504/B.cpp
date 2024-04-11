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
VI pa,pb;
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
fenw fa,fb,fr;
VI resd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  pa.resize(n);
  pb.resize(n);
  forn(i,n)
    cin>>pa[i];
  forn(i,n)
    cin>>pb[i];
  fa.ini(n);
  fb.ini(n);
  fr.ini(n);
  resd.resize(n);
  for(in i=n-1;i>=0;--i){
    in cc=fa.sm(pa[i])+fb.sm(pb[i]);
    fa.ad(pa[i],1);
    fb.ad(pb[i],1);
    resd[i]+=cc;
    if(i>0)
      resd[i-1]+=resd[i]/(n-i);
    resd[i]%=(n-i);
  }
  forn(i,n){
    in mn=0;
    in mx=n;
    in md;
    while(mx-mn>1){
      md=(mx+mn)/2;
      if(md-fr.sm(md-1)<=resd[i])
	mn=md;
      else
	mx=md;
    }
    fr.ad(mn,1);
    cout<<mn<<" ";
  }
  cout<<"\n";
  return 0;
}