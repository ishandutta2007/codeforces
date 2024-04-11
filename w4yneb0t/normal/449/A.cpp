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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
// (n/a)*(m/(k-a)) maxed
in n,m,k;
in best=-1;
const in magic=100000;
in comp,ns,ms;
void proc(in a){
  if(a>0 && a<=n){
    comp=k-a;
    if(comp<=0)
      comp=1;
    if(comp<=m){
      ns=n/a;
      ms=m/comp;
      if(ns*ms>best)
	best=ns*ms;
    }
  }
}
int main(){
  cin>>n>>m>>k;
  if((n-1)+(m-1)<k){
    cout<<-1<<endl;
    return 0;
  }
  k+=2;
  for(in i=1;i<=magic;i++){
    proc(i);
    proc(n/i);
  }
  cout<<best<<endl;
  return 0;
}