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
VVI bd;
VI r,c;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  bd.resize(n,VI(m));
  forn(i,n){
    forn(j,m){
      cin>>bd[i][j];
    }
  }
  in mn=1e9;
  forn(i,n)
    mn=min(mn,bd[i][0]);
  r.resize(n);
  c.resize(m);
  c[0]=mn;
  forn(i,n){
    r[i]=bd[i][0]-mn;
  }
  for(in i=1;i<m;++i){
    c[i]=bd[0][i]-r[0];
  }
  forn(i,n){
    forn(j,m){
      if(bd[i][j]!=r[i]+c[j]){
	cout<<-1<<endl;
	return 0;
      }
    }
  }
  if(n<m){
    mn=1e9;
    forn(i,m){
      mn=min(mn,c[i]);
    }
    forn(i,m)
      c[i]-=mn;
    forn(i,n)
      r[i]+=mn;
  }
  in sm=0;
  forn(i,n)
    sm+=r[i];
  forn(i,m)
    sm+=c[i];
  cout<<sm<<endl;
  forn(i,n){
    forn(j,r[i])
      cout<<"row "<<(i+1)<<"\n";
  }
  forn(i,m){
    forn(j,c[i])
      cout<<"col "<<(i+1)<<"\n";
  }
  return 0;
}