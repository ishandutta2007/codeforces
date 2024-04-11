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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI mar;
in n;
VI rsp;
void adr(in a, in b){
  rsp[a]++;
  if(b+1<sz(rsp))
    rsp[b+1]--;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  rsp.resize(n+3,0);
  for(in i=1;i<n;i++){
    in cpr=i-1;
    in ck=1;
    while(ck<=n-1 && (i-1)/ck!=(i-1)/(ck+1)){
      cpr=(i-1)/ck;
      if(mar[i]<mar[cpr])
	adr(ck,ck);
      ck++;
    }
    in cmx;
    do{
      if(ck>=n)break;
      if(cpr==0)
	cmx=10000000LL;
      else
	cmx=(i-1)/cpr;
      if(mar[i]<mar[cpr])
	adr(ck,cmx);
      ck=cmx+1;
      cpr=(i-1)/ck;
    }while(1);
  }
  in csm=0;
  forn(i,n){
    csm+=rsp[i];
    if(i)
      cout<<csm<<" ";
  }
  cout<<"\n";
  return 0;
}