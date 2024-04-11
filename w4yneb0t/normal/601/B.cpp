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
in ab(in a){
  return (a<0?-a:a);
}
vector<pair<in,in> > mxs;
in n,q;
VI tar;
set<in> tkn;
VI nxtl,nxtr;
in ans(in tl, in tr){
  --tl;
  in sm=0;
  in lend,rend;
  forv(i,mxs){
    if(mxs[i].second>=tr || mxs[i].second<=tl)
      continue;
    lend=max(tl,nxtl[mxs[i].second]);
    rend=min(tr,nxtr[mxs[i].second]);
    sm+=mxs[i].first*(rend-mxs[i].second)*(mxs[i].second-lend);
  }
  return sm;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  tar.resize(n-1);
  in prv;
  cin>>prv;
  in nxt;
  nxtl.resize(n-1);
  nxtr.resize(n-1);
  forn(i,n-1){
    cin>>nxt;
    tar[i]=ab(nxt-prv);
    prv=nxt;
    mxs.PB(MP(tar[i],i));
  }
  sort(all(mxs));
  reverse(all(mxs));
  tkn.insert(-1);
  tkn.insert(n-1);
  set<in>::iterator it;
  forv(i,mxs){
    it=tkn.upper_bound(mxs[i].second);
    nxtr[mxs[i].second]=*it;
    --it;
    nxtl[mxs[i].second]=*it;
    tkn.insert(mxs[i].second);
  }
  in tl,tr;
  forn(i,q){
    cin>>tl>>tr;
    --tl;
    --tr;
    cout<<ans(tl,tr)<<endl;
  }
  return 0;
}