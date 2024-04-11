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
VI rvl;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  rvl.resize(n);
  forn(i,n){
    cin>>rvl[i];
    rvl[i]-=(n-1-i);
  }
  sort(all(rvl));
  forn(i,n-1){
    if(rvl[i]==rvl[i+1]){
      cout<<":("<<endl;
      return 0;
    }
  }
  forn(i,n){
    cout<<rvl[i]+(n-1-i)<<" ";
  }
  cout<<endl;
  return 0;
}