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
in n,m;
vector<in> w;
vector<in> ord;
vector<int> dn;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m;
  dn.resize(n,0);
  w.resize(n);
  ord.resize(m);
  forn(i,n)
    cin>>w[i];
  forn(i,m){
    cin>>ord[i];ord[i]--;
  }
  in sm=0;
  forn(i,m){
    for(in j=i-1;j>=0 && ord[j]!=ord[i];--j){
      if(!dn[ord[j]]){
	dn[ord[j]]=1;
	sm+=w[ord[j]];
      }
    }
    for(in j=i-1;j>=0 && ord[j]!=ord[i];--j){
      dn[ord[j]]=0;
    }
  }
  cout<<sm<<endl;
  return 0;
}