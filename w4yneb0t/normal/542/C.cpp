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
VI f;
VI rsf;
in gcd(in a, in b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  f.resize(n);
  rsf.resize(n);
  forn(i,n){
    cin>>f[i];
    --f[i];
  }
  in mn=0;
  in cc=1;
  forn(i,n){
    in u=i;
    in v=u;
    forn(j,n+3){
      v=f[v];
      if(v==u){
	rsf[u]=j+1;
	break;
      }
    }
  }
  forn(i,n){
    in u=i;
    in c=0;
    while(!rsf[u]){
      ++c;
      u=f[u];
    }
    mn=max(mn,c);
    cc=cc*(rsf[u]/gcd(rsf[u],cc));
  }
  in cu=cc;
  while(cu<mn)
    cu+=cc;
  cout<<cu<<endl;
  return 0;
}