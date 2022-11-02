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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
multiset<in> s;
in ggt(in a, in b){
  if(b==0)
    return a;
  return ggt(b,a%b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in t;
  forn(z,n*n){
    cin>>t;
    s.insert(-t);
  }
  VI a;
  forn(z,n){
    t=-(*(s.begin()));
    s.erase(s.find(-t));
    forv(i,a){
      s.erase(s.find(-ggt(a[i],t)));
      s.erase(s.find(-ggt(a[i],t)));
    }
    a.PB(t);
  }
  forv(i,a)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}