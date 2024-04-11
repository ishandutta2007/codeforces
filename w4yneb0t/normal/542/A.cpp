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
struct vid{
  in l,r,id;
  vid(in a=0, in b=0, in c=0){
    l=a;
    r=b;
    id=c;
  }
  bool operator<(const vid cp)const{
    if(l!=cp.l)
      return l<cp.l;
    return r>cp.r;
  }
};
vector<vid> vids;
VI ml,mr,mb,lc,rc;
in btr(in a, in b){
  if(a==-1)
    return b;
  if(b==-1)
    return a;
  if(vids[a].r-vids[a].l>vids[b].r-vids[b].l)
    return a;
  return b;
}
in bv(in l, in r, in id=0){
  if(r<ml[id] || l>mr[id])
    return -1;
  if(l<=ml[id] && r>=mr[id])
    return mb[id];
  return btr(bv(l,r,lc[id]),bv(l,r,rc[id]));
}
void bnd(in l, in r, in id){
  ml.PB(l);
  mr.PB(r);
  mb.PB(0);
  lc.PB(0);
  rc.PB(0);
  if(l==r){
    mb[id]=l;
    return;
  }
  in md=(l+r)/2;
  lc[id]=sz(ml);
  bnd(l,md,sz(ml));
  rc[id]=sz(ml);
  bnd(md+1,r,sz(ml));
  mb[id]=btr(mb[lc[id]],mb[rc[id]]);
}
void bld(){
  bnd(0,sz(vids)-1,0);
}
in bst=0;
in bi=-1;
in bj=-1;
void cka(in l, in r, in c, in i, in j){
  if(l>r)
    return;
  if((r-l)*c>bst){
    bst=(r-l)*c;
    bi=i;
    bj=j;
  }
}
void qr(in l, in r, in c, in id){
  in mn=-1;
  in mx=sz(vids);
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(vids[md].l<=l)
      mn=md;
    else
      mx=md;
  }
  in ls=mn+1;
  if(mn!=-1)
    cka(l,min(r,vids[mn].r),c,vids[mn].id,id);
  mn=-1;
  mx=sz(vids);
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(vids[md].r>=r)
      mx=md;
    else
      mn=md;
  }
  in rs=mx-1;
  if(mx!=sz(vids))
    cka(max(l,vids[mx].l),r,c,vids[mx].id,id);
  if(ls<=rs){
    in tid=bv(ls,rs);
    assert(tid!=-1);
    cka(vids[tid].l,vids[tid].r,c,vids[tid].id,id);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  in tl,tr;
  forn(z,n){
    cin>>tl>>tr;
    vids.PB(vid(tl,tr,z+1));
  }
  sort(all(vids));
  n=1;
  for(in i=1;i<sz(vids);++i){
    if(vids[i].r>vids[n-1].r)
      vids[n++]=vids[i];
  }
  vids.resize(n);
  bld();
  in tc;
  forn(z,m){
    cin>>tl>>tr>>tc;
    qr(tl,tr,tc,z+1);
  }
  cout<<bst<<endl;
  if(bst>0)
    cout<<bi<<" "<<bj<<endl;
  return 0;
}