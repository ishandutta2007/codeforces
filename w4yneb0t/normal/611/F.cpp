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
in fnd(in sx, in sy, const VI& frcx, const VI& frcy, bool foth=1){
  in sm=0;
  if(foth)
    sm=fnd(sy,sx,frcy,frcx,0)%mdl;
  in mny=1;
  for(in i=1;i<=sx;++i){
    while(mny<=sy && frcy[mny]<frcx[i])
      ++mny;
    sm+=(frcx[i]%mdl*(sy-mny+1));
    sm%=mdl;
  }
  return sm;
}
in stup(bool c){
  if(c)
    return 1;
  return -1;
}
const in mx=500009;
const in inf=mx*mx+9;
in n;
void gnr(VI& frc, in ofs){
  in nxt=0;
  while(frc[nxt]<inf)
    ++nxt;
  while(nxt<sz(frc)){
    frc[nxt]=frc[nxt-ofs]+n;
    ++nxt;
  }
}
map<char,in> dc;
VVI d={{0,1},{1,0},{-1,0},{0,-1}};
string mvs;
VI mvid;
VVI frc;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in h,w;
  cin>>n>>h>>w;
  cin>>mvs;
  frc=VVI(4,VI(mx,inf));
  dc['R']=0;
  dc['L']=3;
  dc['U']=1;
  dc['D']=2;
  mvid.resize(n);
  forn(i,n)
    mvid[i]=dc[mvs[i]];
  forn(i,4)
    frc[i][0]=0;
  in ctm=0;
  in clx=0;
  in cly=0;
  forn(i,n){
    clx+=d[mvid[i]][0];
    cly+=d[mvid[i]][1];
    ++ctm;
    if(mvid[i]==0 || mvid[i]==3)
      frc[mvid[i]][max(0LL,stup(mvid[i]==0)*cly)]=min(frc[mvid[i]][max(0LL,stup(mvid[i]==0)*cly)],ctm);
    else
      frc[mvid[i]][max(0LL,stup(mvid[i]==1)*clx)]=min(frc[mvid[i]][max(0LL,stup(mvid[i]==1)*clx)],ctm);
  }
  if(clx==0 && cly==0){
    VI mrc(4,0);
    forn(i,4){
      while(frc[i][mrc[i]+1]<inf)
	++mrc[i];
    }
    if(mrc[0]+mrc[3]<w && mrc[1]+mrc[2]<h){
      cout<<-1<<endl;
      return 0;
    }
  }
  if(clx>0)
    gnr(frc[1],clx);
  if(clx<0)
    gnr(frc[2],-clx);
  if(cly>0)
    gnr(frc[0],cly);
  if(cly<0)
    gnr(frc[3],-cly);
  in lopt;
  for(in i=0;i<=h;++i){
    if(frc[1][i+1]>frc[2][h-i]){
      lopt=i-1;
      break;
    }
  }
  in lrt;
  for(in i=0;i<=w;++i){
    if(frc[0][i+1]>frc[3][w-i]){
      lrt=i-1;
      break;
    }
  }
  in sm=0;
  if(lopt>=0 && lrt>=0)
    sm+=fnd(lopt+1,lrt+1,frc[1],frc[0]);
  if(lopt>=0 && lrt<w-1)
    sm+=fnd(lopt+1,w-lrt-1,frc[1],frc[3]);
  if(lopt<h-1 && lrt>=0)
    sm+=fnd(h-lopt-1,lrt+1,frc[2],frc[0]);
  if(lopt<h-1 && lrt<w-1)
    sm+=fnd(h-lopt-1,w-lrt-1,frc[2],frc[3]);
  sm%=mdl;
  cout<<sm<<endl;
  return 0;
}