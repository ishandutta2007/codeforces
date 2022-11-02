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
string stt;
in n;
vector<string> qs;
vector<char> qo;
const in mdl=1000000007LL;
const in ph=mdl-1;
vector<in> becs,becm;
in p10(in a){
  in r=1;
  for(in i=35;i>=0;i--){
    r*=r;
    r%=mdl;
    if(a&(1LL<<i)){
      r*=10;
      r%=mdl;
    }
  }
  return r;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>stt;
  qo.PB('0');
  qs.PB(stt);
  cin>>n>>ws;
  forn(i,n){
    getline(cin,stt);
    qo.PB(stt[0]);
    qs.PB(stt.substr(3,sz(stt)-3));
  }
  becs.resize(10,1);
  becm.resize(10);
  forn(i,10)
    becm[i]=i;
  reverse(all(qo));
  reverse(all(qs));
  forv(zz,qo){
    in cg=qo[zz]-'0';
    string nu=qs[zz];
    in nl=0;
    in nm=0;
    for(in i=sz(nu)-1;i>=0;i--){
      nm+=becm[nu[i]-'0']*p10(nl);
      nm%=mdl;
      nl+=becs[nu[i]-'0'];
      nl%=ph;
    }
    becs[cg]=nl;
    becm[cg]=nm;
  }
  cout<<becm[0]<<endl;
  return 0;
}