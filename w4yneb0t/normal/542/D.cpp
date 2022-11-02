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
in ispp(in a){
  for(in i=2;i*i<=a;++i){
    if(a%i)
      continue;
    while(a%i==0)
      a/=i;
    if(a!=1)
      return 0;
    return i;
  }
  return a;
}
map<in,in> dcd;
set<in> dvst;
vector<map<set<in>,in> > tv;
map<in,in> cna;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in a;
  cin>>a;
  VI dv;
  for(in i=1;i*i<=a;++i){
    if(a%i)
      continue;
    dv.PB(i);
    if(i!=a/i)
      dv.PB(a/i);
  }
  sort(all(dv));
  forv(i,dv)
    dcd[dv[i]]=i;
  tv.resize(sz(dv));
  forv(i,dv)
    dvst.insert(dv[i]);
  VI gdv,gp;
  in t;
  forv(i,dv){
    in tp=dv[i]-1;
    if(tp>1){
      t=ispp(tp);
      if(t){
	gdv.PB(dv[i]);
	gp.PB(t);
	++cna[t];
      }
    }
  }
  set<in> ts;
  tv[dcd[1]][ts]=1;
  in c,p;
  in cca;
  forv(i,gdv){
    c=gdv[i];
    p=gp[i];
    cca=cna[p];
    for(in j=sz(dv)-1;j>=0;--j){
      if(c<=a/dv[j] && dvst.find(c*dv[j])!=dvst.end()){
	in ol=dcd[dv[j]];
	in nu=dcd[dv[j]*c];
	if(cca>1){
	  fors(hh,tv[ol]){
	    if(hh->first.find(p)==hh->first.end()){
	      ts=hh->first;
	      ts.insert(p);
	      tv[nu][ts]+=hh->second;
	    }
	  }
	}
	else{
	  fors(hh,tv[ol]){
	    tv[nu][hh->first]+=hh->second;
	  }
	}
      }
    }
  }
  in sm=0;
  fors(i,tv[dcd[a]])
    sm+=i->second;
  cout<<sm<<endl;
  return 0;
}