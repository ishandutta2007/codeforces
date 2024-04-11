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
const in inf=1000000000LL;
in n,s,l;
VI a;
VI bst;
in mxel(multiset<in>& sn){
  auto it=sn.end();
  --it;
  return *it;
}
multiset<in> sn;
multiset<in> hvopt;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>s>>l;
  a=VI(n);
  bst=VI(n+1,inf);
  bst[0]=0;
  forn(i,n)
    cin>>a[i];
  in nxtad=0;
  in nxtrm=0;
  forn(i,n){
    sn.insert(a[i]);
    while(nxtad<=i+1-l)
      hvopt.insert(bst[nxtad++]);
    while(nxtrm<nxtad && (mxel(sn)-*sn.begin()>s)){
      sn.erase(sn.find(a[nxtrm]));
      hvopt.erase(hvopt.find(bst[nxtrm++]));
    }
    assert(sz(hvopt)==nxtad-nxtrm);
    if(!hvopt.empty())
      bst[i+1]=1+*hvopt.begin();
  }
  cout<<(bst[n]>=inf?-1:bst[n])<<endl;
  return 0;
}