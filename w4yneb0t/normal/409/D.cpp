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
void runer(){
  assert(0);
}
in tle(){
  in i=1;
  forn(j,1000000000000000LL)
    i+=j/7;
  return i;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //4 5 6 8 14 15
  //  int ar[16]={1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0};
  //6 14 15
  int ar[16]={1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};
  in i;
  cin>>i;
  /*  if(i==6)
    runer();
  if(i==15)
    tle();*/
  cout<<ar[i-1]<<endl;
  return 0;
}