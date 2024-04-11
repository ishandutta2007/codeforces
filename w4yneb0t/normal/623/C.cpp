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
in sq(in a){
  return a*a;
}
struct pt{
  in x,y;
  pt(in a=0, in b=0){
    x=a;
    y=b;
  }
  bool operator<(const pt cp)const{
    return y<cp.y;
  }
};
in n;
vector<pt> pts;
VI exto[2];
VI exfrm[2];
bool isok(in hgr, in md, in i1, in i2){
  VI ex={0,0};
  if(i1>0){
    ex[0]=exto[0][i1-1];
    ex[1]=exto[1][i1-1];
  }
  if(i2<n-1){
    ex[0]=min(ex[0],exfrm[0][i2+1]);
    ex[1]=max(ex[1],exfrm[1][i2+1]);
  }
  if(sq(ex[1]-ex[0])>md)
    return 0;
  if(sq(ex[1])+sq(hgr)>md)
    return 0;
  if(sq(ex[0])+sq(hgr)>md)
    return 0;
  return 1;
}
bool ispo(in md){
  in hgr;
  in lwid=0;
  forn(i,n){
    hgr=pts[i].y;
    if(hgr>0)
      break;
    while((lwid<n) && (lwid<=i || (sq(hgr-pts[lwid].y)<=md && sq(hgr)>=sq(pts[lwid].y)))){
      ++lwid;
    }
    --lwid;
    while(lwid>i && sq(pts[lwid].y)>sq(hgr))
      --lwid;
    ++lwid;
    if(isok(hgr,md,i,lwid-1))
      return 1;
  }
  lwid=n-1;
  for(in i=n-1;i>=0;--i){
    hgr=pts[i].y;
    if(hgr<0)
      break;
    while((lwid>=0) && (lwid==i || (sq(hgr-pts[lwid].y)<=md && sq(hgr)>=sq(pts[lwid].y)))){
      --lwid;
    }
    ++lwid;
    while(lwid<i && sq(pts[lwid].y)>sq(hgr))
      ++lwid;
    --lwid;
    if(isok(hgr,md,lwid+1,i))
      return 1;
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  pts.resize(n);
  forn(i,n)
    cin>>pts[i].x>>pts[i].y;
  in mny=1e9;
  in mxy=-mny;
  in mnx=1e9;
  in mxx=-mnx;
  forn(i,n){
    mny=min(mny,pts[i].y);
    mxy=max(mxy,pts[i].y);
    mnx=min(mnx,pts[i].x);
    mxx=max(mxx,pts[i].x);
  }
  sort(all(pts));
  forn(z,2){
    exto[z].resize(n);
    exfrm[z].resize(n);
  }
  exto[0][0]=exto[1][0]=pts[0].x;
  exfrm[0][n-1]=exfrm[1][n-1]=pts[n-1].x;
  for(in i=1;i<n;++i){
    exto[0][i]=min(exto[0][i-1],pts[i].x);
    exto[1][i]=max(exto[1][i-1],pts[i].x);
  }
  for(in i=n-2;i>=0;--i){
    exfrm[0][i]=min(exfrm[0][i+1],pts[i].x);
    exfrm[1][i]=max(exfrm[1][i+1],pts[i].x);
  }
  in mn=-1;
  in mx=1e17;
  mx=min(mx,sq(mxy-mny));
  mx=min(mx,sq(mxx-mnx));
  in md;
  while(mx-mn>1){
    md=(mn+mx)/2;
    if(ispo(md))
      mx=md;
    else
      mn=md;
  }
  cout<<mx<<endl;
  return 0;
}