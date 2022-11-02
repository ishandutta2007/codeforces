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
  in n;
  cin>>n;
  in lsf=0;
  in bst=0;
  in lst=100000000000LL;
  in tp;
  forn(i,n){
    cin>>tp;
    if(tp<lst)
      lsf=0;
    lst=tp;
    lsf++;
    bst=max(bst,lsf);
  }
  cout<<bst<<endl;
  return 0;
}