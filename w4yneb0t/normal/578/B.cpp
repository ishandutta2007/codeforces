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
VI pfx,sfx,mar;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k,x;
  cin>>n>>k>>x;
  pfx=sfx=mar=VI(n);
  forn(i,n)
    cin>>mar[i];
  for(in i=n-2;i>=0;i--)
    sfx[i]=(sfx[i+1]|mar[i+1]);
  for(in i=1;i<n;i++)
    pfx[i]=(pfx[i-1]|mar[i-1]);
  in tml=1;
  forn(i,k)
    tml*=x;
  in bst=0;
  in vl;
  forn(i,n){
    vl=(pfx[i]|sfx[i]|(mar[i]*tml));
    bst=max(bst,vl);
  }
  cout<<bst<<"\n";
  return 0;
}