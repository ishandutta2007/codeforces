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
struct fenw{
  VI fw;
  in n;
  void ini(in pn){
    n=pn;
    fw.clear();
    fw.resize(n,0);
  }
  void ad(in l, in x){
    while(l<n){
      fw[l]+=x;
      l|=(l+1);
    }
  }
  in sm(in l){
    in r=0;
    while(l>=0){
      r+=fw[l];
      l&=(l+1);
      --l;
    }
    return r;
  }
};
map<char,in> dcd;
const in mx=1e5+9;
vector<vector<vector<fenw> > > fw; // fw[a][b][c] has 1 at i if letter a is at i*b+c
void adt(in l, in typ, in f){
  for(in lt=1;lt<=10;++lt){
    fw[typ][lt][l%lt].ad(l/lt,f);
  }
}
string s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  dcd['A']=0;
  dcd['C']=1;
  dcd['G']=2;
  dcd['T']=3;
  fw.resize(4);
  forn(i,4){
    fw[i].resize(11);
    for(in j=1;j<=10;++j){
      fw[i][j].resize(j);
      forn(k,j){
	fw[i][j][k].ini(mx/j+9);
      }
    }
  }
  cin>>s;
  forv(i,s){
    adt(i,dcd[s[i]],1);
  }
  in q;
  cin>>q;
  in typ,x,l,r;
  char c;
  string e;
  in sm;
  in lt;
  in loc;
  forn(z,q){
    cin>>typ;
    if(typ==1){
      cin>>x>>c;
      --x;
      adt(x,dcd[s[x]],-1);
      s[x]=c;
      adt(x,dcd[s[x]],1);
    }
    else{
      cin>>l>>r>>e;
      --l;
      --r;
      sm=0;
      lt=sz(e);
      forv(i,e){
	loc=(l+i)%lt;
	if(r-loc>=0)
	  sm+=fw[dcd[e[i]]][lt][loc].sm((r-loc)/lt);
	if(l-1-loc>=0)
	  sm-=fw[dcd[e[i]]][lt][loc].sm((l-1-loc)/lt);
      }
      cout<<sm<<"\n";
    }
  }
  return 0;
}