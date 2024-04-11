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
const in mdl=1000000007LL;
in n;
vector<in> p;
vector<vector<in> > ttg;
in tt(in a, in b){
  in& ct=ttg[a][b];
  if(ct!=-1)
    return ct;
  if(a==b)
    return ct=0;
  return ct=(1+tt(p[a],a)+1+tt(a+1,b))%mdl;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  p.resize(n);
  forn(i,n){
    cin>>p[i];
    p[i]--;
  }
  ttg.resize(n+1,vector<in>(n+1,-1));
  cout<<tt(0,n)<<endl;
  return 0;
}