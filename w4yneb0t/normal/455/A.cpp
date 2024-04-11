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
const in mx=100009;
vector<in> ct;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  ct.resize(mx);
  in n;
  cin>>n;
  in a;
  forn(i,n){
    cin>>a;
    ct[a]++;
  }
  in mt=0;
  in mn=0;
  in nmn;
  forn(i,mx){
    nmn=mt;
    mt=mn+ct[i]*i;
    mn=nmn;
    if(mn>mt)
      mt=mn;
  }
  cout<<mt<<endl;
  return 0;
}