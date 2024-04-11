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
void imp(){
  cout<<-1<<endl;
  exit(0);
}
in n,l,r;
VI a,c;
vector<pair<in,in> > tind;
VI ans;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>l>>r;
  a.resize(n);
  c.resize(n);
  ans.resize(n);
  forn(i,n)
    cin>>a[i];
  forn(i,n){
    cin>>c[i];
    tind.PB(MP(c[i],i));
  }
  sort(all(tind));
  in pv=-1e18;
  in ci;
  forn(i,n){
    ci=tind[i].second;
    //b-a[ci]>pv
    ans[ci]=pv+a[ci]+1;
    if(ans[ci]<l)
      ans[ci]=l;
    if(ans[ci]>r)
      imp();
    pv=ans[ci]-a[ci];
  }
  forn(i,n)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}