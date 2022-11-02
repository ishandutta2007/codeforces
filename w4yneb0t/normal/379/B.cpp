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
  in n;
  in a[309];
  cin>>n;
  forn(i,n)
    cin>>a[i];
  forn(i,n){
    forn(j,a[i]){
      if(i!=n-1)
	cout<<"RL";
      else
	cout<<"LR";
      cout<<"P";
    }
    if(i!=n-1)
      cout<<"R";
  }
  cout<<endl;
  return 0;
}