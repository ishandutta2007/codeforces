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
void imp(){
  cout<<-1<<"\n";
  exit(0);
}
VI ntr;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k,a,b,c,d;
  cin>>n>>k>>a>>b>>c>>d;
  if(n==4)
    imp();
  if(k<n+1)
    imp();
  in r=1;
  while(r==a || r==b || r==c || r==d)
    ++r;
  for(in i=1;i<=n;++i){
    if(i==a || i==b || i==c || i==d || i==r)
      continue;
    ntr.PB(i);
  }
  cout<<a<<" ";
  forv(i,ntr)
    cout<<ntr[i]<<" ";
  cout<<c<<" "<<r<<" "<<d<<" "<<b<<"\n";
  cout<<c<<" ";
  for(in i=sz(ntr)-1;i>=0;--i)
    cout<<ntr[i]<<" ";
  cout<<a<<" "<<r<<" "<<b<<" "<<d<<"\n";
  return 0;
}