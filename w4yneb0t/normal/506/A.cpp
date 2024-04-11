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
const in zr=300;
const in mx=30009;
in rs=0;
VVI bst;
VI cn;
in d;
void ad(in lc, in jp, in g){
  if(lc<0 || lc>=mx)
    return;
  if(jp<=0)
    return;
  if(g<0)
    return;
  rs=max(rs,g+cn[lc]);
  bst[lc][jp-d+zr]=max(bst[lc][jp-d+zr],g+cn[lc]);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  bst.resize(mx,VI(2*zr,-1000000LL));
  in n;
  cin>>n>>d;
  cn.resize(mx);
  in ta;
  forn(z,n){
    cin>>ta;
    cn[ta]++;
  }
  rs=cn[d];
  bst[d][zr]=cn[d];
  forv(i,bst){
    forv(j,bst[i]){
      ad(i+j+d-zr,j+d-zr,bst[i][j]);
      ad(i+j+d-zr+1,j+d-zr+1,bst[i][j]);
      ad(i+j+d-zr-1,j+d-zr-1,bst[i][j]);
    }
  }
  cout<<rs<<endl;
  return 0;
}