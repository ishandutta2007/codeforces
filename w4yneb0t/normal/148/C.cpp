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
  cout<<-1<<endl;
  exit(0);
}
const in mx=50000;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,a,b;
  cin>>n>>a>>b;
  VI cc;
  in l=1;
  cc.PB(l);
  in sm=1;
  forn(i,b){
    l=sm+1;
    cc.PB(l);
    sm+=l;
    if(l>mx)
      imp();
  }
  if(b==0 && a>0){
    cc.PB(l);
  }
  forn(i,a){
    ++l;
    cc.PB(l);
    if(l>mx)
      imp();
  }
  if(sz(cc)>n)
    imp();
  while(sz(cc)<n)
    cc.PB(1);
  forn(i,n)
    cout<<cc[i]<<" ";
  cout<<endl;
  return 0;
}