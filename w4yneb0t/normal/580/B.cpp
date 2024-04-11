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
vector<pair<in,in> > fd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,d;
  cin>>n>>d;
  in ta,tb;
  forn(i,n){
    cin>>ta>>tb;
    fd.PB(MP(ta,tb));
  }
  sort(all(fd));
  in nxtad=0;
  in nxtrm=0;
  in sm=0;
  in bst=0;
  while(nxtad<sz(fd)){
    sm+=fd[nxtad].second;
    while(fd[nxtrm].first<=fd[nxtad].first-d){
      sm-=fd[nxtrm++].second;
    }
    ++nxtad;
    bst=max(bst,sm);
  }
  cout<<bst<<endl;
  return 0;
}