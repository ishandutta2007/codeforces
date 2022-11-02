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
struct resinf{
  in leftseg,rightseg,longest,totl;
  resinf(in a=0){
    leftseg=a;
    rightseg=a;
    longest=a;
    totl=1;
  }
  resinf operator+(const resinf& cp)const{
    resinf r;
    r.totl=totl+cp.totl;
    r.leftseg=leftseg;
    r.rightseg=cp.rightseg;
    if(leftseg==totl)
      r.leftseg+=cp.leftseg;
    if(cp.rightseg==cp.totl)
      r.rightseg+=rightseg;
    r.longest=max(longest,cp.longest);
    r.longest=max(r.longest,rightseg+cp.leftseg);
    return r;
  }
};
resinf ers(0);
struct treenode{
  in leftend,rightend,leftchild,rightchild;
  resinf res;
  treenode(in l, in r){
    leftend=l;
    rightend=r;
    leftchild=-1;
    rightchild=-1;
    res=resinf(0);
  }
};
VI roots;
vector<treenode> trs;
in buildtr(in l, in r){
  in cind=sz(trs);
  trs.PB(treenode(l,r));
  if(r!=l){
    in m=(l+r)/2;
    in tpc=buildtr(l,m);
    trs[cind].leftchild=tpc;
    tpc=buildtr(m+1,r);
    trs[cind].rightchild=tpc;
    trs[cind].res=trs[trs[cind].leftchild].res+trs[trs[cind].rightchild].res;
  }
  return cind;
}
in add1(in tt, in loc){
  in tpl=trs[tt].leftend;
  in tpr=trs[tt].rightend;
  if(tpl>loc || tpr<loc)return tt;
  in cind=sz(trs);
  trs.PB(treenode(tpl,tpr));
  if(tpl==tpr){
    trs[cind].res=resinf(1);
    return cind;
  }
  in t1=add1(trs[tt].leftchild,loc);
  trs[cind].leftchild=t1;
  t1=add1(trs[tt].rightchild,loc);
  trs[cind].rightchild=t1;
  trs[cind].res=trs[trs[cind].leftchild].res+trs[trs[cind].rightchild].res;
  return cind;
}
resinf fnd(in tt, in l, in r){
  if(l>trs[tt].rightend || r<trs[tt].leftend)return ers;
  if(l<=trs[tt].leftend && r>=trs[tt].rightend)return trs[tt].res;
  return fnd(trs[tt].leftchild,l,r)+fnd(trs[tt].rightchild,l,r);
}
vector<pair<in,in> > plks;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ers.totl=0;
  in n,m;
  cin>>n;
  plks.resize(n);
  roots.resize(n+1);
  forn(i,n){
    cin>>plks[i].first;
    plks[i].second=i;
  }
  sort(all(plks));
  reverse(all(plks));
  roots[0]=buildtr(0,n-1);
  forv(i,plks){
    roots[i+1]=add1(roots[i],plks[i].second);
  }
  cin>>m;
  in l,r,w;
  forn(z,m){
    cin>>l>>r>>w;
    l--;
    r--;
    in mn=0;
    in mx=n;
    in md;
    while(mx-mn>1){
      md=(mn+mx)/2;
      if(fnd(roots[md],l,r).longest>=w)
	mx=md;
      else
	mn=md;
    }
    cout<<plks[mx-1].first<<"\n";
  }
  return 0;
}