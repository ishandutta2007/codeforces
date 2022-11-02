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
vector<vector<pair<in,string> > > tbs;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  tbs.resize(m);
  string nm;
  in scr;
  in reg;
  forn(i,n){
    cin>>nm>>reg>>scr;
    --reg;
    tbs[reg].PB(MP(-scr,nm));
  }
  forn(i,m){
    sort(all(tbs[i]));
    if(sz(tbs[i])>=3 && tbs[i][1].first==tbs[i][2].first){
      cout<<"?\n";
      continue;
    }
    cout<<tbs[i][0].second<<" "<<tbs[i][1].second<<"\n";
  }
  return 0;
}