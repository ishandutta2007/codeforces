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
map<in,in> pphav;
in p2(in a){
  return 1<<a;
}
void fac(in a){
  for(in i=2;i*i<=a;++i){
    if(a%i==0){
      in cp=i;
      in pw=0;
      while(a%i==0){
	a/=i;
	++pw;
      }
      pphav[cp]|=p2(pw);
    }
  }
  if(a!=1)
    pphav[a]|=p2(1);
}
map<in,in> g;
const in mpw=29;
in allbit=p2(mpw+1)-1;
in grund(in msk){
  if(msk&1)
    msk^=1;
  if(g.find(msk)!=g.end())
    return g[msk];
  VI sn(33);
  for(in i=1;(msk&(allbit^(p2(i)-1)))!=0;++i){
    sn[grund((msk&(p2(i)-1))|(msk>>i))]=1;
  }
  in r=0;
  while(sn[r])
    ++r;
  return g[msk]=r;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  forn(z,n){
    in a;
    cin>>a;
    fac(a);
  }
  in totgrund=0;
  fors(i,pphav)
    totgrund^=grund(i->second);
  if(totgrund)
    cout<<"Mojtaba"<<endl;
  else
    cout<<"Arpa"<<endl;
  return 0;
}