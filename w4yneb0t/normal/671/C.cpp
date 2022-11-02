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
const in mx=200009;
in sm=0;
VVI ocs;
VVI dvs;
VI mar;
map<in,in> pm;
map<in,in>::iterator it,it2;
void adp(in mi, in mj, in fc){
  if(mi>mj)
    return;
  it=pm.upper_bound(mi);
  it2=it;
  --it;
  in dh=it->second;
  if(dh>=mj)
    return;
  pm[mi]=mj;
  while(1){
    sm+=(it2->first-mi)*fc*(mj-dh);
    if(it2->second>mj){
      break;
    }
    mi=it2->first;
    dh=it2->second;
    it=it2;
    ++it2;
    pm.erase(it);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  ocs.resize(mx);
  dvs.resize(mx);
  for(in i=1;i<mx;++i){
    for(in j=i;j<mx;j+=i)
      dvs[j].PB(i);
  }
  forn(i,n){
    forv(j,dvs[mar[i]]){
      ocs[dvs[mar[i]][j]].PB(i);
    }
  }
  for(in i=-2;i<=n+3;++i){
    pm[i]=i-1;
  }
  in ts;
  for(in i=mx-1;i>=0;--i){
    ts=sz(ocs[i]);
    if(ts<=1)
      continue;
    adp(ocs[i][1]+1,n-1,i);
    adp(0,ocs[i][ts-2]-1,i);
    adp(ocs[i][0]+1,ocs[i][ts-1]-1,i);
  }
  cout<<sm<<endl;
  return 0;
}