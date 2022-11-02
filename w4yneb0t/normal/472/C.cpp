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
in n;
vector<string> f,s;
vector<in> p;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  f.resize(n);
  s=f;
  p.resize(n);
  forn(i,n){
    cin>>f[i]>>s[i];
    if(s[i]<f[i])
      swap(s[i],f[i]);
  }
  forn(i,n){
    cin>>p[i];
    p[i]--;
  }
  string prv;
  forn(i,n){
    if(i==0){
      prv=f[p[i]];
      continue;
    }
    if(prv<f[p[i]]){
      prv=f[p[i]];
      continue;
    }
    if(prv<s[p[i]]){
      prv=s[p[i]];
      continue;
    }
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  return 0;
}