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
struct pt{
  vector<in> x;
  pt(in a=0, in b=0, in c=0){x.resize(3);x[0]=a;x[1]=b;x[2]=c;}
  pt operator+(const pt& cp)const{
    return pt(x[0]+cp.x[0],x[1]+cp.x[1],x[2]+cp.x[2]);
  }
  pt operator-(const pt& cp)const{
    return pt(x[0]-cp.x[0],x[1]-cp.x[1],x[2]-cp.x[2]);
  }
  in nrm(){
    return x[0]*x[0]+x[1]*x[1]+x[2]*x[2];
  }
  in spr(const pt& cp)const{
    return x[0]*cp.x[0]+x[1]*cp.x[1]+x[2]*cp.x[2];
  }
  bool operator<(const pt& cp)const{
    forn(i,3)
      if(x[i]!=cp.x[i])
	return x[i]<cp.x[i];
    return 0;
  }
  bool operator==(const pt& cp)const{
    forn(i,3)
      if(x[i]!=cp.x[i])
	return 0;
    return 1;
  }
};
bool iscb(vector<pt> pts){
  for(in i=7;i>=0;i--){
    pts[i]=pts[i]-pts[0];
  }
  vector<in> cns;
  vector<in> tpdt(8,0);
  in mds=1000000000000000000LL;
  for(in i=1;i<8;i++){
    tpdt[i]=pts[i].nrm();
    mds=min(mds,tpdt[i]);
  }
  if(mds==0)
    return 0;
  for(in i=1;i<8;i++){
    if(mds==tpdt[i])
      cns.PB(i);
  }
  if(sz(cns)!=3)
    return 0;
  forn(i,3){
    forn(j,i){
      if(pts[cns[i]].spr(pts[cns[j]])!=0)
	return 0;
    }
  }
  vector<pt> sgt;
  forn(msk,8){
    pt nu;
    forn(i,3){
      if(msk&(1LL<<i))
	nu=nu+pts[cns[i]];
    }
    sgt.PB(nu);
  }
  sort(all(sgt));
  sort(all(pts));
  return sgt==pts;
}
vector<pt> pts;
bool sch(in i){
  if(i==8){
    if(iscb(pts)){
      cout<<"YES"<<endl;
      forn(j,8){
	forn(k,3){
	  cout<<pts[j].x[k]<<" ";
	}
	cout<<endl;
      }
      return 1;
    }
    return 0;
  }
  sort(all(pts[i].x));
  do{
    if(sch(i+1))
      return 1;
  }while(next_permutation(all(pts[i].x)));
  return 0;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  pts.resize(8);
  forn(i,8){
    forn(j,3){
      cin>>pts[i].x[j];
    }
  }
  if(!sch(1))
    cout<<"NO"<<endl;
  return 0;
}