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
map<string,set<string> > mad;
map<set<string>,vector<string> > hs;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  string tp;
  string adr,quer;
  in slc;
  forn(zz,n){
    cin>>tp;
    slc=0;
    adr.clear();
    quer.clear();
    forv(i,tp){
      if(tp[i]=='/')
	++slc;
      if(slc<=2)
	adr+=tp[i];
      else
	quer+=tp[i];
    }
    mad[adr].insert(quer);
  }
  fors(i,mad)
    hs[i->second].PB(i->first);
  in cct=0;
  fors(i,hs){
    if(sz(i->second)>1){
      ++cct;
    }
  }
  cout<<cct<<"\n";
  fors(i,hs){
    if(sz(i->second)>1){
      forv(j,i->second){
	cout<<(i->second)[j]<<" ";
      }
      cout<<"\n";
    }
  }
  return 0;
}