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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n;
vector<in> pr,clr;
vector<in> w[2];
const in mdl=1000000007LL;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  pr.resize(n,0);
  w[0].resize(n,1);
  w[1].resize(n,0);
  clr=pr;
  forn(i,n-1){
    cin>>pr[i+1];
  }
  forn(i,n)
    cin>>clr[i];
  for(in i=n-1;i>=0;i--){
    if(clr[i]){
      w[1][i]=w[0][i];
      w[0][i]=0;
    }
    if(i>0){
      w[1][pr[i]]*=w[0][i]+w[1][i];
      w[1][pr[i]]%=mdl;
      w[1][pr[i]]+=w[0][pr[i]]*w[1][i];
      w[1][pr[i]]%=mdl;
      w[0][pr[i]]*=w[0][i]+w[1][i];
      w[0][pr[i]]%=mdl;
    }
  }
  cout<<w[1][0]<<endl;
  return 0;
}