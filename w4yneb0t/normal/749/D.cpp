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
VI id,b;
vector<set<in> > bds;
VI osn;
VI ord;
VI bd;
VI vcbd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  osn.resize(n+2);
  bds.resize(n+2);
  bds[0].insert(0);
  bds[n+1].insert(-1);
  id.PB(n+1);
  id.PB(0);
  b.PB(-1);
  b.PB(0);
  in ta,tb;
  forn(z,n){
    cin>>ta>>tb;
    id.PB(ta);
    b.PB(tb);
    bds[ta].insert(tb);
  }
  for(in i=sz(b)-1;i>=0;--i){
    if(osn[id[i]])
      continue;
    osn[id[i]]=1;
    ord.PB(id[i]);
  }
  bd.resize(n+2);
  in q;
  cin>>q;
  in tk;
  forn(zz,q){
    cin>>tk;
    vcbd.resize(tk);
    forn(z,tk){
      cin>>vcbd[z];
      bd[vcbd[z]]=1;
    }
    in fs=0;
    while(bd[ord[fs]])
      ++fs;
    in sc=fs+1;
    while(bd[ord[sc]])
      ++sc;
    fs=ord[fs];
    sc=ord[sc];
    auto tt=bds[sc].end();
    --tt;
    auto it=bds[fs].upper_bound(*tt);
    cout<<fs<<" "<<*it<<"\n";
    forn(z,tk){
      bd[vcbd[z]]=0;
    }
  }
  return 0;
}