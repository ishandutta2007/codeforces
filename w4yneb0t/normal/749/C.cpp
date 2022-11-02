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
set<pair<in,in> > s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  string ts;
  cin>>n>>ts;
  forv(i,ts){
    if(ts[i]=='D')
      s.insert(MP(i,0));
    else
      s.insert(MP(i,1));
  }
  VI va(2);
  while(1){
    in psz=sz(s);
    auto it=s.begin();
    auto it2=it;
    while(it!=s.end()){
      if(va[it->second]){
	--va[it->second];
	it2=it;
	++it;
	s.erase(it2);
	continue;
      }
      ++va[!(it->second)];
      ++it;
    }
    if(sz(s)==psz)
      break;
  }
  assert(sz(s));
  if(s.begin()->second)
    cout<<"R"<<endl;
  else
    cout<<"D"<<endl;
  return 0;
}