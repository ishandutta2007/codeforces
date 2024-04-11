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
typedef long long ll;
typedef vector<in> VI;
typedef vector<VI> VVI;
const in mdl=1000000007;
in n;
VI mar;
in wys[77][1<<20];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  mar.resize(n);
  string tps;
  cin>>tps;
  forn(i,n)
    mar[i]=tps[i]-'0';
  for(in i=0;i<=n;++i){
    wys[i][0]=1;
  }
  for(in i=0;i<n;++i){
    in nn=0;
    for(in j=i;j<n;++j){
      nn=2*nn+mar[j];
      if(nn>20)
	break;
      if(nn==0)
	continue;
      forn(msk,(1<<20)){
	wys[j+1][msk|(1<<(nn-1))]+=wys[i][msk];
	wys[j+1][msk|(1<<(nn-1))]%=mdl;
      }
    }
  }
  in sm=0;
  for(in i=0;i<=n;++i){
    for(in m=1;m<=20;++m){
      sm+=wys[i][(1<<m)-1];
      sm%=mdl;
    }
  }
  cout<<sm<<endl;
  return 0;
}