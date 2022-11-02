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
  vector<string> fc(n);
  forn(i,n)
    cin>>fc[i];
  in sm=0;
  string tc="face";
  sort(all(tc));
  forn(i,n-1){
    forn(j,sz(fc[i])-1){
      string cc;
      cc+=fc[i][j];
      cc+=fc[i][j+1];
      cc+=fc[i+1][j];
      cc+=fc[i+1][j+1];
      sort(all(cc));
      sm+=(cc==tc);
    }
  }
  cout<<sm<<endl;
  return 0;
}