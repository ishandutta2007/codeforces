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
in ab(in a){
  return a<0?-a:a;
}
in vl(VI a){
  in bstpf=0;
  in csm=0;
  in n=sz(a);
  in r=-1e18;
  in f=1;
  forn(i,n-1){
    csm+=ab(a[i+1]-a[i])*f;
    f*=-1;
    r=max(r,csm-bstpf);
    if(i%2==1)
      bstpf=min(bstpf,csm);
  }
  return r;
}
VI a;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  in mx=-1e18;
  mx=max(mx,vl(a));
  reverse(all(a));
  a.pop_back();
  reverse(all(a));
  mx=max(mx,vl(a));
  cout<<mx<<endl;
  return 0;
}