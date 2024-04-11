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
VI hv;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  hv.resize(100009);
  in ta;
  forn(z,n){
    cin>>ta;
    ++hv[ta];
  }
  in mx=1;
  for(in i=2;i<sz(hv);++i){
    in s=0;
    for(in j=i;j<sz(hv);j+=i)
      s+=hv[j];
    mx=max(mx,s);
  }
  cout<<mx<<endl;
  return 0;
}