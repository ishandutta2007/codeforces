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
const in sml=20;
const in magic=(1LL<<sml);
in a;
vector<vector<in> > cont;
vector<in> p2;
in ans=0;
const in mdl=1000000007LL;
in ect(in s){
  in r=1;
  forn(i,sml)
    if(s&(1LL<<i))
      r^=1;
  return r;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  cont.resize(magic,vector<in>(2));
  forn(i,n){
    cin>>a;
    cont[a][0]++;
  }
  for(in i=0;i<sml;i++){
    forn(msk,magic){
      cont[msk][(i+1)&1]=cont[msk][i&1];
      if(!(msk&(1LL<<i))){
	cont[msk][(i+1)&1]+=cont[msk|(1LL<<i)][i&1];
      }
    }
  }
  p2.resize(magic);
  p2[0]=1;
  for(in i=1;i<magic;i++){
    p2[i]=(p2[i-1]*2)%mdl;
  }
  ans=p2[n];
  for(in msk=1;msk<magic;msk++){
    if(ect(msk))
      ans+=p2[cont[msk][0]];
    else
      ans-=p2[cont[msk][0]];
  }
  ans%=mdl;
  ans+=mdl;
  ans%=mdl;
  cout<<ans<<endl;
  return 0;
}