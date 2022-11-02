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
    fw.resize(n,-1e9);
  }
  void ad(in l, in x){
    while(l<n){
      fw[l]=max(fw[l],x);
      l|=(l+1);
    }
  }
  in sm(in l){
    in r=-1e9;
    while(l>=0){
      r=max(r,fw[l]);
      l&=(l+1);
      --l;
    }
    return r;
  }
};
in bst=0;
void ad(fenw& f, in b, in x, in c, in& bstc, in bstd){
  if(x>c)
    return;
  if(b>bstc){
    bstc=b;
    bst=max(bst,bstc+bstd);
  }
  bst=max(bst,b+f.sm(c-x));
  f.ad(x,b);
}
fenw cf,df;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  in bstc=-1e9;
  in bstd=-1e9;
  in c,d;
  cin>>n>>c>>d;
  const in mx=100009;
  cf.ini(mx);
  df.ini(mx);
  in b,x;
  char typ;
  forn(z,n){
    cin>>b>>x>>typ;
    if(typ=='C'){
      ad(cf,b,x,c,bstc,bstd);
      continue;
    }
    if(typ=='D'){
      ad(df,b,x,d,bstd,bstc);
      continue;
    }
  }
  cout<<bst<<endl;
  return 0;
}