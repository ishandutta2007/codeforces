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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
typedef pair<in,in> PII;
VVI egs,revid;
in n;
VVI totsd,bgd;
vector<PII> tota;
vector<vector<PII> > cpsz;
VI ise,tid,iseid;
void arr(vector<PII>& v){
  if(sz(v)<=2){
    if(sz(v)==2){
      if(v[1]>v[0])
	swap(v[0],v[1]);
    }
    return;
  }
  if(v[2]>v[1])
    swap(v[2],v[1]);
  if(v[1]>v[0])
    swap(v[1],v[0]);
  v.pop_back();
}
in tots(in u, in pr, in egid);
in bg(in u, in pr, in egid);
in bgc(in u, in pr, in egid){
  assert(egs[u][egid]==pr);
  if(tots(u,pr,egid)<=n/2)
    return tots(u,pr,egid);
  if(sz(cpsz[u])==0){
    forv(i,egs[u]){
      if(egs[u][i]==pr)
	continue;
      cpsz[u].PB(MP(bg(egs[u][i],u,revid[u][i]),egs[u][i]));
      arr(cpsz[u]);
    }
    ise[u]=pr;
    iseid[u]=revid[u][egid];
  }
  if(ise[u]!=-1 && ise[u]!=pr){
    cpsz[u].PB(MP(bg(ise[u],u,iseid[u]),ise[u]));
    arr(cpsz[u]);
  }
  forv(i,cpsz[u]){
    if(cpsz[u][i].second==pr)
      continue;
    return cpsz[u][i].first;
  }
  assert(0);
  return 0;
}
in totsc(in u, in pr, in egid){
  assert(egs[u][egid]==pr);
  if(tota[u].first!=-1){
    PII tp=tota[u];
    return tp.first+tots(tp.second,u,tid[u])-tots(pr,u,revid[u][egid]);
  }
  in s=1;
  forv(i,egs[u]){
    if(egs[u][i]==pr){
      tid[u]=revid[u][i];
      continue;
    }
    s+=tots(egs[u][i],u,revid[u][i]);
  }
  tota[u]=MP(s,pr);
  return s;
}
in bg(in u, in pr, in egid){
  assert(egs[u][egid]==pr);
  if(bgd[u][egid]!=-1)
    return bgd[u][egid];
  return bgd[u][egid]=bgc(u,pr,egid);
}
in tots(in u, in pr, in egid){
  assert(egs[u][egid]==pr);
  if(totsd[u][egid]!=-1)
    return totsd[u][egid];
  return totsd[u][egid]=totsc(u,pr,egid);
}
bool isg(in u){
  in v;
  forv(i,egs[u]){
    v=egs[u][i];
    if(tots(v,u,revid[u][i])-bg(v,u,revid[u][i])>n/2)
      return 0;
  }
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  tid.resize(n,-1);
  tota.resize(n,MP(-1,-1));
  totsd.resize(n);
  bgd.resize(n);
  revid.resize(n);
  cpsz.resize(n);
  iseid.resize(n,-1);
  ise.resize(n,-1);
  egs.resize(n);
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    revid[ta].PB(sz(egs[tb]));
    revid[tb].PB(sz(egs[ta]));
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(i,n){
    totsd[i].resize(sz(egs[i]),-1);
    bgd[i].resize(sz(egs[i]),-1);
  }
  forn(i,n){
    cout<<isg(i)<<" ";
  }
  cout<<"\n";
  return 0;
}