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
in n,m;
VI d,h;
in ab(in a){
  return a<0?-a:a;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  d.resize(m);
  h.resize(m);
  forn(i,m)
    cin>>d[i]>>h[i];
  in mht=max(h[0]+d[0]-1,h[m-1]+(n-d[m-1]));
  forn(i,m-1){
    if(ab(d[i]-d[i+1])<ab(h[i]-h[i+1])){
      cout<<"IMPOSSIBLE"<<endl;
      return 0;
    }
    in dfr=d[i+1]-d[i];
    in sth=max(h[i],h[i+1]);
    in eth=min(h[i],h[i+1]);
    dfr-=(sth-eth);
    mht=max(mht,sth+dfr/2);
  }
  cout<<mht<<endl;
  return 0;
}