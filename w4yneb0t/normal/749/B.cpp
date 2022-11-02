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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<pair<in,in> > s;
  VI x(3),y(3);
  forn(i,3)
    cin>>x[i]>>y[i];
  forn(a,3){
    forn(b,3){
      forn(c,3){
	if(a==b || a==c || b==c)
	  continue;
	s.insert(MP(x[a]+x[b]-x[c],y[a]+y[b]-y[c]));
      }
    }
  }
  cout<<sz(s)<<endl;
  fors(i,s)
    cout<<i->first<<" "<<i->second<<endl;
  return 0;
}