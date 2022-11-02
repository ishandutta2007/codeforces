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
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
vector<in> a;
in best=1;
in n;
vector<in> cind;
void tr(in l, in r){
  if(l>r || r>=n || l<0)
    return;
  if(r-l+1<=best)
    return;
  in sf=0;
  for(in i=l;i<r;i++){
    if(a[i]>=a[i+1]){
      sf++;
      if(i==l || i+1==r)
	continue;
      if(a[i-1]+2<=a[i+1])
	continue;
      if(a[i]+2<=a[i+2])
	continue;
      return;
    }
  }
  if(sf>1)
    return;
  best=r-l+1;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  cind.PB(0);
  forn(i,n-1){
    if(a[i]>=a[i+1]){
      cind.PB(i);
    }
  }
  cind.PB(n-1);
  forv(i,cind){
    for(in j=i+1;j<=i+2 && j<sz(cind);j++){
      tr(cind[i],cind[j]);
      tr(cind[i],cind[j]+1);
      tr(cind[i]+1,cind[j]);
      tr(cind[i]+1,cind[j]+1);
    }
  }
  cout<<best<<endl;
  return 0;
}