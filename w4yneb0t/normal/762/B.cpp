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
vector<pair<in,in> > mice;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in usb,ps2,both;
  cin>>usb>>ps2>>both;
  in totg=0;
  in totcost=0;
  in n;
  cin>>n;
  mice.resize(n);
  string ts;
  forn(i,n){
    cin>>mice[i].first>>ts;
    if(ts=="USB"){
      mice[i].second=0;
      continue;
    }
    if(ts=="PS/2"){
      mice[i].second=1;
      continue;
    }
    assert(0);
  }
  sort(all(mice));
  forv(i,mice){
    if(mice[i].second==0 && usb){
      --usb;
      ++totg;
      totcost+=mice[i].first;
      continue;
    }
    if(mice[i].second==1 && ps2){
      --ps2;
      ++totg;
      totcost+=mice[i].first;
      continue;
    }
    if(both){
      --both;
      ++totg;
      totcost+=mice[i].first;
    }
  }
  cout<<totg<<" "<<totcost<<endl;
  return 0;
}