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
in t,T,n,m;
VI l,r;
in n1,n2;
in mn1,mx1,mn2,mx2;
struct cond{
  in mn,mx;
  cond(in a=0, in b=0){mn=a;mx=b;}
  bool operator<(const cond cp)const{
    if(mn!=cp.mn)return mn<cp.mn;
    return mx>cp.mx;
  }
};
vector<cond> conds,rconds;
VVI egs;
VI vis;
in cmn[2];
in cmx[2];
bool fll;
void dfs(in u, in sd){
  if(vis[u]!=-1){
    if(vis[u]!=sd)fll=1;
    return;
  }
  vis[u]=sd;
  cmn[sd]=max(cmn[sd],l[u]);
  cmx[sd]=min(cmx[sd],r[u]);
  forv(i,egs[u])
    dfs(egs[u][i],!sd);
}
bool isbi(in i){
  fll=0;
  forn(i,2){
    cmn[i]=0;
    cmx[i]=T;
  }
  dfs(i,0);
  if(cmn[0]>cmx[0] || cmn[1]>cmx[1])return 0;
  if(cmn[0]>cmn[1]){
    swap(cmn[0],cmn[1]);
    swap(cmx[0],cmx[1]);
  }
  if(cmx[0]>cmx[1]){
    conds.PB(cond(cmn[1],cmx[1]));
    mn1=max(mn1,cmn[0]);
    mn2=max(mn2,cmn[0]);
    mx1=min(mx1,cmx[0]);
    mx2=min(mx2,cmx[0]);
  }
  else{
    mn1=max(mn1,cmn[0]);
    mn2=max(mn2,cmn[1]);
    mx1=min(mx1,cmx[0]);
    mx2=min(mx2,cmx[1]);
  }
  return !fll;
}
VI sol;
VI viss;
void rdfs(in u, in ofs){
  if(viss[u])return;
  viss[u]=1;
  sol[u]=(vis[u]+ofs)%2;
  forv(i,egs[u])
    rdfs(egs[u][i],ofs);
}
void mksol(in i){
  fll=0;
  forn(i,2){
    cmn[i]=0;
    cmx[i]=T;
  }
  dfs(i,0);
  if(n1>=cmn[0] && n1<=cmx[0] && n2>=cmn[1] && n2<=cmx[1])
    rdfs(i,0);
  else
    rdfs(i,1);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>t>>T>>n>>m;
  viss.resize(n,0);
  l.resize(n);
  r.resize(n);
  vis.resize(n,-1);
  forn(i,n)
    cin>>l[i]>>r[i];
  egs.resize(n);
  in ta,tb;
  forn(i,m){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  mn1=0;
  mx1=T;
  mn2=0;
  mx2=T;
  forn(i,n){
    if(vis[i]==-1){
      if(!isbi(i)){
	cout<<"IMPOSSIBLE"<<endl;return 0;
      }
    }
  }
  sort(all(conds));
  forv(i,conds){
    while(sz(rconds)>0 && conds[i].mx<=rconds.back().mx)
      rconds.pop_back();
    rconds.PB(conds[i]);
  }
  conds=rconds;
  rconds.clear();
  while(sz(conds)>0 && conds.back().mn>conds[0].mx){
    mn2=max(mn2,conds.back().mn);
    mx2=min(mx2,conds.back().mx);
    conds.pop_back();
  }
  if(mn1>mx1 || mn2>mx2 || mn1>mx2){
    cout<<"IMPOSSIBLE"<<endl;return 0;
  }
  forv(i,conds){
    if(conds[i].mx<mn2 || conds[i].mn>mx2){
      mn1=max(mn1,conds[i].mn);
      mx1=min(mx1,conds[i].mx);
      continue;
    }
    if(conds[i].mx<mn1 || conds[i].mn>mx1){
      mn2=max(mn2,conds[i].mn);
      mx2=min(mx2,conds[i].mx);
      continue;
    }
    rconds.PB(conds[i]);
  }
  conds=rconds;
  rconds.clear();
  if(mn1>mx1 || mn2>mx2 || mn1>mx2){
    cout<<"IMPOSSIBLE"<<endl;return 0;
  }
  forn(i,sz(conds)+1){
    in tpmn1=mn1;
    in tpmx1=mx1;
    in tpmn2=mn2;
    in tpmx2=mx2;
    if(i>0){
      tpmn1=max(tpmn1,conds[i-1].mn);
      tpmx1=min(tpmx1,conds[0].mx);
    }
    if(i<sz(conds)){
      tpmn2=max(tpmn2,conds.back().mn);
      tpmx2=min(tpmx2,conds[i].mx);
    }
    if(tpmn1<=tpmx1 && tpmn2<=tpmx2){
      in totmn=tpmn1+tpmn2;
      in totmx=tpmx1+tpmx2;
      if(totmx<t || totmn>T)continue;
      n1=tpmn1;
      n2=tpmn2;
      if(n1+n2<t){
	n1+=t-n2-n1;
	if(n1>tpmx1){
	  n2+=n1-tpmx1;
	  n1=tpmx1;
	}
      }
      assert(n1>=tpmn1 && n1<=tpmx1 && n2>=tpmn2 && n2<=tpmx2);
      vis=VI(n,-1);
      sol.resize(n);
      forn(j,n){
	if(vis[j]==-1)
	  mksol(j);
      }
      assert(n1+n2>=t && n1+n2<=T);
      forn(j,n){
	if(sol[j]==0)
	  assert(l[j]<=n1 && r[j]>=n1);
	else
	  assert(l[j]<=n2 && r[j]>=n2);
	forv(k,egs[j])
	  assert(sol[egs[j][k]]!=sol[j]);
      }
      cout<<"POSSIBLE\n";
      cout<<n1<<" "<<n2<<"\n";
      forn(j,n)
	cout<<sol[j]+1;
      cout<<"\n";
      return 0;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;return 0;
  return 0;
}