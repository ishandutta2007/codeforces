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
  in n,l;
  cin>>n>>l;
  VI a(n);
  VI b(n);
  forn(i,n)
    cin>>a[i];
  forn(i,n)
    cin>>b[i];
  VI da;
  forn(i,n-1)
    da.PB(a[i+1]-a[i]);
  da.PB(a[0]+l-a[n-1]);
  VI db;
  forn(i,n-1)
    db.PB(b[i+1]-b[i]);
  db.PB(b[0]+l-b[n-1]);
  VI tt;
  forn(i,n){
    tt=da;
    rotate(tt.begin(),tt.begin()+i,tt.end());
    if(tt==db){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}