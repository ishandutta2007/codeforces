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
in n,k;
string mst;
vector<int> mmtc,sol;
in ntm=0;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>k;
  cin>>mst;
  if(k==1){
    forn(i,n)
      cout<<"1";
    cout<<"\n";
    return 0;
  }
  sol.resize(n,0);
  mmtc.resize(n+1,0);
  in lgst=1;
  in lgup=0;
  while(lgup+1<n && mst[lgup]==mst[lgup+1])
    ++lgup;
  mmtc[0]=n;
  mmtc[1]=lgup;
  for(in i=2;i<n;i++){
    if(lgst+lgup>i)
      mmtc[i]=mmtc[i-lgst];
    if(mmtc[i]+i>=lgst+lgup){
      mmtc[i]=lgst+lgup-i;
      if(mmtc[i]<0)mmtc[i]=0;
      lgst=i;
      lgup=mmtc[i];
      while(lgup+i<n && mst[lgup]==mst[lgup+i])
	++lgup;
      mmtc[i]=lgup;
    }
  }
  for(in i=1;i<n;i++){
    if(ntm<k*i-1)
      ntm=k*i-1;
    if(mmtc[i]+i>=i*k){
      while(ntm<(k+1)*i && ntm<mmtc[i]+i){
	sol[ntm]=1;
	++ntm;
      }
    }
  }
  forn(i,n){
    cout<<sol[i];
  }
  cout<<"\n";
  return 0;
}