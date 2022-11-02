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
in gcd(in a, in b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
map<in,set<in> > incl;
map<in,in> bst;
map<in,in> wtg;
VI pfs;
in phi;
in m;
in p2(in a){
  return (1LL<<a);
}
in pw(in a, in b, in lm=62){
  a%=m;
  if(a<0)
    a+=m;
  in r=1;
  for(in i=lm;i>=0;--i){
    r=r*r%m;
    if(b&p2(i))
      r=r*a%m;
  }
  return r;
}

in inv(in a){
  return pw(a,phi-1);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n>>m;
  in cm=m;
  phi=m;
  for(in i=2;i<=cm;++i){
    if(cm%i==0){
      while(cm%i==0)
	cm/=i;
      phi*=i-1;
      phi/=i;
    }
  }
  forn(i,m)
    incl[gcd(i,m)].insert(i);
  in a;
  forn(i,n){
    cin>>a;
    incl[gcd(a,m)].erase(a);
  }
  in sbst;
  in cw;
  fors(it,incl){
    sbst=0;
    cw=-1;
    fors(it2,bst){
      if(it2->first!=it->first && it->first%it2->first==0){
	if(it2->second>sbst){
	  sbst=it2->second;
	  cw=it2->first;
	}
      }
    }
    bst[it->first]=sbst+sz(it->second);
    wtg[it->first]=cw;
  }
  in cr=m;
  while(cr!=-1){
    fors(j,incl[cr])
      pfs.PB(*j);
    cr=wtg[cr];
  }
  reverse(all(pfs));
  cout<<sz(pfs)<<"\n";
  cout<<pfs[0]<<" ";
  in g1;
  for(in i=1;i<sz(pfs);++i){
    g1=gcd(pfs[i-1],m);
    cout<<inv(pfs[i-1]/g1)*pfs[i]/g1%m<<" ";
  }
  cout<<"\n";
  return 0;
}