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
in n;
VI bg;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  bg.resize(n);
  in sm1=0;
  forn(i,n){
    cin>>bg[i];
    sm1+=bg[i];
  }
  sort(all(bg));
  for(in i=1;i<n;i++){
    if(bg[i]<=bg[i-1])
      bg[i]=bg[i-1]+1;
  }
  forn(i,n)
    sm1-=bg[i];
  cout<<-sm1<<endl;
  return 0;
}