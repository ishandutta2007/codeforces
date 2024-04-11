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
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
vector<in> cc;
in n,inter;
void opt(bool ok){
  if(ok)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}
vector<in> ct1;
vector<vector<in> > ofsize;
vector<in> locmx;
vector<bool> istree;
vector<in> treesize;
vector<vector<bool> > isforest;
vector<vector<bool> > issplit;
in mssz;
in leafs;
void proc(){
  mssz=1LL<<inter;
  ct1.resize(mssz);
  ofsize.resize(inter+1);
  treesize.resize(mssz);
  locmx.resize(mssz);
  forn(m,mssz){
    in ct=0;
    in tsz=1;
    in locs=-1;
    forn(i,inter){
      if(m&(1LL<<i)){
	if(cc[i]>tsz){
	  tsz=cc[i];
	  locs=i;
	}
	ct++;
      }
    }
    locmx[m]=locs;
    treesize[m]=tsz;
    ct1[m]=ct;
    ofsize[ct].PB(m);
  }
  istree.resize(mssz,0);
  isforest.resize(mssz,vector<bool>(n+1,0));
  issplit=isforest;
  istree[0]=1;
  for(in i=1;i<=leafs;i++){
    isforest[0][i]=1;
    if(i>1)
      issplit[0][i]=1;
  }
  for(in l=1;l<=inter;l++){
    forv(zz,ofsize[l]){
      in msk=ofsize[l][zz];
      in rt=locmx[msk];
      if(issplit[msk^(1LL<<rt)][treesize[msk]-1]){
	istree[msk]=1;
	isforest[msk][treesize[msk]]=1;
      }
      forn(mtl,mssz){
	if(mtl&(~msk))
	  continue;
	in mtr=msk^mtl;
	if(!istree[mtl])
	  continue;
	for(in rsz=1;rsz<=n;rsz++){
	  if(!isforest[mtr][rsz])
	    continue;
	  in lneed=treesize[mtl]-ct1[mtl]+rsz-ct1[mtr];
	  if(lneed>leafs)
	    continue;
	  isforest[msk][treesize[mtl]+rsz]=issplit[msk][treesize[mtl]+rsz]=1;
	}
      }
    }
  }
  opt(istree[mssz-1] && treesize[mssz-1]==n);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cc.resize(n);
  forn(i,n)
    cin>>cc[i];
  if(n==1){
    opt(cc[0]==1);
    return 0;
  }
  if(n==2){
    opt(0);
    return 0;
  }
  leafs=0;
  in nonleafs;
  forn(i,n)
    leafs+=(cc[i]==1);
  in tdg=leafs;
  nonleafs=n-leafs;
  if(nonleafs==0){
    opt(0);
    return 0;
  }
  tdg+=2+(nonleafs-1)*3;
  if(tdg>(n-1)*2){
    opt(0);
    return 0;
  }
  sort(cc.begin(),cc.end());
  reverse(cc.begin(),cc.end());
  inter=nonleafs;
  proc();
  return 0;
}