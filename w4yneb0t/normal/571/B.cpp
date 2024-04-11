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
const in inf=1000000000000LL;
in smsz,lgsz,smct,lgct;
in n;
VI a;
VI bst[2];
void upd(in sw, in nw, in nutot){
  forn(i,smct+1)
    bst[nw][i]=inf;
  in ced,cct,clg;
  forn(i,smct+1){
    clg=nutot-i;
    if(clg<0)break;
    if(clg>lgct)continue;
    ced=i*smsz+clg*lgsz;
    if(clg>0){
      cct=a[ced-1]-a[ced-lgsz];
      bst[nw][i]=min(bst[nw][i],bst[sw][i]+cct);
    }
    if(i>0){
      cct=a[ced-1]-a[ced-smsz];
      bst[nw][i]=min(bst[nw][i],bst[sw][i-1]+cct);
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in k;
  cin>>n>>k;
  smsz=n/k;
  smct=k-n%k;
  lgsz=smsz+1;
  lgct=n%k;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  sort(all(a));
  forn(z,2)
    bst[z]=VI(smct+1,inf);
  in sw=0;
  in nw=0;
  bst[sw][0]=0;
  forn(z,k){
    sw=z%2;
    nw=!sw;
    upd(sw,nw,z+1);
  }
  cout<<bst[nw][smct]<<endl;
  return 0;
}