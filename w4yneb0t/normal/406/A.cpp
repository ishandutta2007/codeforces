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
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
int n,q;
int sg=0;
int a;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  forn(i,n){
    forn(j,n){
      cin>>a;
      if(i==j && a==1)
	sg^=1;
    }
  }
  cin>>q;
  forn(i,q){
    cin>>n;
    if(n==3){
      cout<<sg;
      continue;
    }
    sg^=1;
    cin>>n;
  }
  cout<<"\n";
  return 0;
}