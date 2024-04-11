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
in c, hr, hb, wr, wb;
in bst=0;
const in lmt=40000;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>c>>hr>>hb>>wr>>wb;
  if(hr*wb<hb*wr){
    swap(hr,hb);
    swap(wr,wb);
  }
  in scr;
  if(wr>lmt){
    for(in nr=0;nr*wr<=c;nr++){
      scr=hr*nr+hb*((c-nr*wr)/wb);
      if(scr>bst)bst=scr;
    }
  }
  else{
    for(in nb=0;nb<=wr && nb*wb<=c;nb++){
      scr=hb*nb+hr*((c-nb*wb)/wr);
      if(scr>bst)bst=scr;
    }
  }
  cout<<bst<<endl;
  return 0;
}