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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  in dbl=0;
  for(in z=1;;++z){
    if(z%2 && !(z%3) && m)
      --m;
    if(z%3 && !(z%2) && n)
      --n;
    if(!(z%2) && !(z%3))
      ++dbl;
    if(dbl>=n+m){
      cout<<z<<endl;
      break;
    }
  }
  return 0;
}