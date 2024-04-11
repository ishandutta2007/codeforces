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
const in mdl=1e9+7;
in p2(in a){
  return 1LL<<a;
}
VVI nov;
string s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  cin>>s;
  nov.resize(n+1,VI(p2(n)));
  forn(i,p2(n)){
    if(s[i]=='1'){
      nov[0][i]=1;
    }
  }
  forn(i,n){
    for(in j=i;j>=0;--j){
      forn(msk,p2(n)){
	nov[j+1][msk^p2(i)]+=nov[j][msk];
      }
    }
  }
  in tsum=0;
  forn(i,n+1){
    forn(msk,p2(n)){
      tsum+=nov[0][msk]*nov[i][msk]%mdl*p2(n-i);
      tsum%=mdl;
    }
  }
  tsum*=3;
  tsum%=mdl;
  if(tsum<0)
    tsum+=mdl;
  cout<<tsum<<endl;
  return 0;
}