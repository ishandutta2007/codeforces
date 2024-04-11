#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) ((v).size())
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
int main(){
  in a,b,sm,w;
  sm=0;
  w=0;
  cin>>a>>b;
  while(a>0 || w>=b){
    a+=w/b;
    w%=b;
    sm+=a;
    w+=a;
    a=0;
  }
  cout<<sm<<endl;
  return 0;
}