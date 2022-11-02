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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
multiset<in> st;
multiset<in>::iterator it;
bool ex(in a, in b){
  it=st.lower_bound(a);
  if(it==st.end())
    return 0;
  return (*it)<b;
}
in p2(in a){
  return 1LL<<a;
}
void fop(in x){
  in ssf=0;
  in cb;
  for(in i=30;i>=0;--i){
    cb=!!(x&p2(i));
    if(!cb)
      ssf|=p2(i);
    if(ex(ssf,ssf+p2(i)))
      continue;
    ssf^=p2(i);
  }
  cout<<(ssf^x)<<"\n";
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in q;
  cin>>q;
  char typ;
  in x;
  st.insert(0);
  forn(z,q){
    cin>>typ>>x;
    if(typ=='+'){
      st.insert(x);
      continue;
    }
    if(typ=='-'){
      st.erase(st.find(x));
      continue;
    }
    if(typ=='?'){
      fop(x);
      continue;
    }
    assert(0);
  }
  return 0;
}