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
VI ans;
VI a;
VI wt;
VVI qrid;
VVI qrloc;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in s=1;
  while((s+1)*(s+1)<=n)
    ++s;
  a.resize(n);
  wt.resize(n);
  forn(i,n)
    cin>>a[i];
  in q;
  cin>>q;
  qrid.resize(s);
  qrloc.resize(s);
  ans.resize(q);
  in p,k;
  forn(z,q){
    cin>>p>>k;
    if(k<s){
      qrid[k].PB(z);
      qrloc[k].PB(p-1);
    }
    else{
      --p;
      in stp=0;
      while(p<n){
	p=p+a[p]+k;
	++stp;
      }
      ans[z]=stp;
    }
  }
  forn(k,s){
    for(in j=n-1;j>=0;--j){
      if(a[j]+j+k>=n)
	wt[j]=1;
      else
	wt[j]=1+wt[a[j]+j+k];
    }
    forv(i,qrid[k])
      ans[qrid[k][i]]=wt[qrloc[k][i]];
  }
  forv(i,ans)
    cout<<ans[i]<<"\n";
  return 0;
}