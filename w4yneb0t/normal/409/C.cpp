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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in a[5];
  in b[5]={1,1,2,7,4};
  forn(i,5)
    cin>>a[i];
  in r=1000000LL;
  forn(i,5)
    if(a[i]/b[i]<r)
      r=a[i]/b[i];
  cout<<r<<endl;
  return 0;
}