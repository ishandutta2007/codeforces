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
VI lcof[2];
VI pbef[2];
in n;
in fnd(in s){
  in cpl=0;
  in nx[2];
  in lsp=-1;
  VI sc={0,0};
  while(cpl<n){
    forn(z,2)
      nx[z]=pbef[z][cpl]-1+s;
    forn(z,2){
      if(nx[z]<sz(lcof[z]))
	nx[z]=lcof[z][nx[z]];
      else
	nx[z]=1000000000LL;
    }
    if(nx[0]==nx[1])
      return -1;
    if(nx[0]<nx[1]){
      lsp=0;
      ++sc[0];
      cpl=nx[0]+1;
    }
    else{
      lsp=1;
      ++sc[1];
      cpl=nx[1]+1;
    }
  }
  if(sc[lsp]>sc[!lsp])
    return sc[lsp];
  return -1;
}
vector<pair<in,in> > solx;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  forn(z,2)
    pbef[z]=VI(n+1);
  in tp;
  forn(i,n){
    forn(z,2)
      pbef[z][i]=sz(lcof[z]);
    cin>>tp;
    tp--;
    lcof[tp].PB(i);
  }
  forn(z,2)
    pbef[z][n]=sz(lcof[z]);
  for(in s=1;s<=n;s++){
    tp=fnd(s);
    if(tp==-1)continue;
    solx.PB(MP(tp,s));
  }
  sort(all(solx));
  cout<<sz(solx)<<"\n";
  forv(i,solx)
    cout<<solx[i].first<<" "<<solx[i].second<<"\n";
  return 0;
}