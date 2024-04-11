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
in gcd(in a, in b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
in kgv(in a, in b){
  return a*b/gcd(a,b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,a,b,p,q;
  cin>>n>>a>>b>>p>>q;
  in sm=(n/a)*p+(n/b)*q-(n/kgv(a,b))*min(p,q);
  cout<<sm<<endl;
  return 0;
}