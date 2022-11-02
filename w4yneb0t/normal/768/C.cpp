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
const in mx=1024;
in hv[2][mx];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k,x;
  cin>>n>>k>>x;
  in nw=0;
  in sw=1;
  in a;
  forn(z,n){
    cin>>a;
    ++hv[nw][a];
  }
  forn(zz,k){
    swap(nw,sw);
    forn(i,mx)
      hv[nw][i]=0;
    in c=1;
    in u;
    forn(i,mx){
      u=(hv[sw][i]+c)/2;
      hv[nw][i^x]+=u;
      hv[nw][i]+=hv[sw][i]-u;
      if(hv[sw][i]&1)
	c^=1;
    }
  }
  in mn=mx+2;
  in mb=-1;
  forn(i,mx){
    if(hv[nw][i]){
      mn=min(mn,i);
      mb=max(mb,i);
    }
  }
  cout<<mb<<" "<<mn<<endl;
  return 0;
}