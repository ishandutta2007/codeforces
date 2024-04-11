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
const in mx=500009;
VI bcd[4]; //a->b, a->c, b->c, c->b;
in p,q,r;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n>>p>>q>>r;
  in a,b,c;
  forn(z,4)
    bcd[z].resize(mx);
  forn(i,n){
    cin>>a>>b>>c;
    bcd[0][a]=max(bcd[0][a],b);
    bcd[1][a]=max(bcd[1][a],c);
    bcd[2][b]=max(bcd[2][b],c);
    bcd[3][c]=max(bcd[3][c],b);
  }
  forn(z,4){
    for(in i=mx-2;i>=0;--i){
      bcd[z][i]=max(bcd[z][i],bcd[z][i+1]);
    }
  }
  in totsm=0;
  in sm=0;
  in mnb=q+1;
  in mnc=r+1;
  for(a=1;a<=p;++a){
    while(mnb>bcd[0][a]+1){
      --mnb;
      sm+=min(r-mnc+1,r-bcd[2][mnb]);
    }
    while(mnc>bcd[1][a]+1){
      --mnc;
      sm+=min(q-mnb+1,q-bcd[3][mnc]);
    }
    totsm+=sm;
  }
  cout<<totsm<<endl;
  return 0;
}