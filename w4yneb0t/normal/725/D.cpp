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
multiset<in> cg;
vector<pair<in,in> > nxt;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in mt,mw;
  cin>>mt>>mw;
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    nxt.PB(MP(-ta,tb-ta+1));
  }
  sort(all(nxt));
  forv(i,nxt)
    nxt[i].first*=-1;
  in bst=1;
  in nn=0;
  while(nn<sz(nxt) && nxt[nn].first>mt){
    cg.insert(nxt[nn].second);
    ++bst;
    ++nn;
  }
  in crp=bst;
  multiset<in>::iterator it;
  in cgv;
  while(1){
    if(cg.empty())
      break;
    it=cg.begin();
    cgv=*it;
    --crp;
    cg.erase(it);
    mt-=cgv;
    if(mt<0)
      break;
    while(nn<sz(nxt) && nxt[nn].first>mt){
      cg.insert(nxt[nn].second);
      ++crp;
      ++nn;
    }
    bst=min(bst,crp);
  }
  cout<<bst<<endl;
  return 0;
}