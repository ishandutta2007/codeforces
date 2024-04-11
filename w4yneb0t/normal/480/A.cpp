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
in bad;
void bd(){
  cout<<bad<<endl;
  exit(0);
}
in n;
vector<pair<in,in> > v;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  v.resize(n);
  forn(i,n)
    cin>>v[i].first>>v[i].second;
  sort(all(v));
  reverse(all(v));
  bad=v[0].first;
  in lat=1000000000000LL;
  in nulat=v[0].second;
  in lst=0;
  forv(i,v){
    if(v[i].first==bad)
      lst=max(lst,v[i].second);
  }
  for(in i=1;i<sz(v);++i){
    if(v[i].first==bad){
      nulat=min(nulat,v[i].second);
      continue;
    }
    if(v[i].first!=v[i-1].first){
      lat=nulat;
      nulat=1000000000000LL;
    }
    if(v[i].second>lat)
      bd();
    if(v[i].first<=lat)
      nulat=min(nulat,v[i].first);
    else
      nulat=min(nulat,v[i].second);
  }
  cout<<lst<<endl;
  return 0;
}