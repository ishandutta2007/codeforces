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
set<string> pn,en;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  string s;
  forn(z,n){
    cin>>s;
    pn.insert(s);
  }
  forn(z,m){
    cin>>s;
    en.insert(s);
  }
  in com=0;
  fors(i,pn)
    if(en.count(*i))
      ++com;
  in l=sz(pn)-com;
  in r=sz(en)-com;
  in tn=0;
  while(1){
    if(com){
      --com;
      tn=!tn;
      continue;
    }
    if(!tn){
      if(l)
	--l;
      else{
	cout<<"NO"<<endl;
	return 0;
      }
    }
    else{
      if(r)
	--r;
      else{
	cout<<"YES"<<endl;
	return 0;
      }
    }
    tn=!tn;
  }
  return 0;
}