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
VI tfc={36000,3600,0,600,60,0,10,1};
in dcd(string s){
  in sm=0;
  assert(sz(s)==sz(tfc));
  forv(i,s)
    sm+=tfc[i]*(s[i]-'0');
  return sm;
}
VI up,dn;
VI ids;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,t;
  cin>>n>>m>>t;
  bool rc=0;
  in co=0;
  in nid=1;
  string s;
  up.resize(1e5);
  dn.resize(1e5);
  forn(i,n){
    cin>>s;
    ++up[dcd(s)];
  }
  in lid=0;
  in ltm=0;
  forv(i,up){
    co-=dn[i];
    if(!up[i])
      continue;
    while(up[i]){
      --up[i];
      if(co==m){
	ids.PB(lid);
	--dn[ltm];
	++dn[i+t];
	ltm=i+t;
	continue;
      }
      ++co;
      if(co==m)
	rc=1;
      ids.PB(nid);
      ++dn[i+t];
      lid=nid;
      ltm=i+t;
      ++nid;
    }
  }
  if(!rc){
    cout<<"No solution"<<endl;
    return 0;
  }
  cout<<nid-1<<"\n";
  forv(i,ids)
    cout<<ids[i]<<"\n";
  return 0;
}