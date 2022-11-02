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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI mar;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  in q;
  cin>>q;
  sort(all(mar));
  in t;
  mar.PB(1e10);
  forn(z,q){
    cin>>t;
    cout<<(upper_bound(all(mar),t)-mar.begin())<<"\n";
  }
  return 0;
}