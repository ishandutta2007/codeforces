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
const in mdl=1000000007LL;
const in mx=1e6+9;
VI fc;
vector<map<in,in> > hct;
map<VI,in> ff;
vector<set<in> > ap;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  fc.resize(mx);
  fc[0]=1;
  for(in i=1;i<sz(fc);++i)
    fc[i]=fc[i-1]*i%mdl;
  in n,m;
  cin>>n>>m;
  ap.resize(m);
  hct.resize(n);
  forn(z,n){
    in g;
    cin>>g;
    in ta;
    forn(zz,g){
      cin>>ta;
      --ta;
      ++hct[z][ta];
      ap[ta].insert(z);
    }
  }
  forn(i,m){
    VI tc;
    fors(j,ap[i]){
      tc.PB(*j);
      tc.PB(hct[*j][i]);
    }
    ++ff[tc];
  }
  in r=1;
  fors(i,ff){
    r=r*fc[i->second]%mdl;
  }
  cout<<r<<endl;
  return 0;
}