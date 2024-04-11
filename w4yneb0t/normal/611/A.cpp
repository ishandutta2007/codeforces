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
void rt(in a){
  cout<<a<<endl;
  exit(0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in x;
  cin>>x;
  string ts;
  cin>>ts>>ts;
  if(ts[0]=='m'){
    if(x<=29)
      rt(12);
    if(x==30)
      rt(11);
    if(x==31)
      rt(7);
  }
  else{
    if(x==5 || x==6)
      rt(53);
    rt(52);
  }
  return 0;
}