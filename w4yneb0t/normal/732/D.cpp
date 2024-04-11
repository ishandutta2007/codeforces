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
VI ld;
VI pn;
VI wd;
VI ex;
in m;
bool isp(in mx){
  forn(i,m)
    ld[i]=-1;
  forn(i,mx){
    if(ex[i]==-1)
      continue;
    ld[ex[i]]=i;
  }
  forn(i,mx)
    wd[i]=-1;
  forn(i,m){
    if(ld[i]==-1)
      return 0;
    wd[ld[i]]=i;
  }
  in psf=0;
  forn(i,mx){
    if(wd[i]==-1){
      ++psf;
      continue;
    }
    psf-=pn[wd[i]];
    if(psf<0)
      return 0;
  }
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n>>m;
  ld.resize(m,-1);
  pn.resize(m);
  ex.resize(n);
  wd.resize(n);
  forn(i,n){
    cin>>ex[i];
    --ex[i];
  }
  forn(i,m)
    cin>>pn[i];
  in mn=0;
  in mx=n+1;
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(isp(md))
      mx=md;
    else
      mn=md;
  }
  if(mx==n+1)
    cout<<-1<<endl;
  else
    cout<<mx<<endl;
  return 0;
}