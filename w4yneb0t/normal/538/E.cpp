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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
in n,m;
VVI egs;
in mapt(in v, in mms){
  if(sz(egs[v])==0)return 1;
  if(mms){
    in cmn=10000000;
    forv(i,egs[v])
      cmn=min(cmn,mapt(egs[v][i],0));
    return cmn;
  }
  in csm=0;
  forv(i,egs[v])
    csm+=mapt(egs[v][i],1);
  return csm;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  egs.resize(n);
  in ta,tb;
  forn(i,n-1){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
  }
  m=0;
  forn(i,n)
    if(sz(egs[i])==0)m++;
  cout<<m+1-mapt(0,1)<<" "<<mapt(0,0)<<endl;
  return 0;
}