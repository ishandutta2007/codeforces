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
map<in,in> fld;
VI cap;
void ad(in i, in x){
  auto it=fld.lower_bound(i);
  if(it==fld.end())
    return;
  it->second+=x;
  if(it->second>=cap[it->first]){
    ad(it->first+1,it->second-cap[it->first]);
    fld.erase(it);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  cap.resize(n);
  forn(i,n)
    cin>>cap[i];
  forn(i,n)
    fld[i]=0;
  in q;
  cin>>q;
  forn(z,q){
    in typ,p,x;
    cin>>typ;
    if(typ==1){
      cin>>p>>x;
      --p;
      ad(p,x);
    }
    else{
      cin>>p;
      --p;
      if(fld.count(p))
	cout<<fld[p]<<"\n";
      else
	cout<<cap[p]<<"\n";
    }
  }
  return 0;
}