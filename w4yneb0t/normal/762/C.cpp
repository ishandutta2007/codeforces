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
void cl(VI& mf, string a, string b){
  for(in i=1;i<sz(mf);++i){
    mf[i]=mf[i-1];
    if(mf[i]<sz(b) && b[mf[i]]==a[i])
      ++mf[i];
  }
}
VI mf,mb;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a,b;
  cin>>a>>b;
  a='$'+a+'$';
  in n=sz(a);
  mf=mb=VI(n);
  cl(mf,a,b);
  reverse(all(a));
  reverse(all(b));
  cl(mb,a,b);
  reverse(all(a));
  reverse(all(b));
  reverse(all(mb));
  in bst=0;
  in bsti=0;
  for(in i=0;i<n-1;++i){
    if(mf[i]+mb[i+1]>bst){
      bst=min(sz(b),mf[i]+mb[i+1]);
      bsti=i;
    }
  }
  if(bst==0){
    cout<<"-"<<endl;
    return 0;
  }
  cout<<b.substr(0,mf[bsti]);
  in lf=bst-mf[bsti];
  cout<<b.substr(sz(b)-lf);
  cout<<endl;
  return 0;
}