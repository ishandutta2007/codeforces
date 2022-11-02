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
const in mx=100009;
VI fof;
VI nf;
VI nxt,pv;
VI adp,ada;
VI hvp,hva;
in mkans(){
  adp.clear();
  ada.clear();
  hvp.clear();
  hva.clear();
  in u=0;
  in sm=0;
  while(u!=mx){
    if(u!=0){
      hvp.PB(u);
      hva.PB(nf[u]);
      assert(nf[u]);
    }
    u=nxt[u];
  }
  in ai=0;
  in hi=0;
  in mp;
  while(1){
    if(ai==sz(adp) && hi==sz(hvp))
      break;
    if(ai==sz(adp)){
      adp.PB(hvp[hi]);
      ada.PB(hva[hi]);
      ++hi;
      continue;
    }
    if(ai+1==sz(adp) && ada[ai]==1){
      if(hi==sz(hvp))
	break;
      adp.PB(hvp[hi]);
      ada.PB(hva[hi]);
      ++hi;
      continue;
    }
    if(ai+1<sz(adp) && adp[ai+1]==adp[ai]){
      ada[ai+1]+=ada[ai];
      ++ai;
      continue;
    }
    if(ada[ai]>=2){
      mp=ada[ai]/2;
      sm+=mp*2*adp[ai];
      while(hi!=sz(hvp) && hvp[hi]<=2*adp[ai]){
	adp.PB(hvp[hi]);
	ada.PB(hva[hi]);
	++hi;
      }
      adp.PB(2*adp[ai]);
      ada.PB(mp);
      ada[ai]-=2*mp;
      if(ada[ai]==0)
	++ai;
      continue;
    }
    sm+=adp[ai]+adp[ai+1];
    while(hi!=sz(hvp) && hvp[hi]<=adp[ai]+adp[ai+1]){
      adp.PB(hvp[hi]);
      ada.PB(hva[hi]);
      ++hi;
    }
    adp.PB(adp[ai]+adp[ai+1]);
    ada.PB(1);
    --ada[ai+1];
    ++ai;
    if(ada[ai]==0)
      ++ai;
  }
  return sm;
}
void ad(in u){
  in ct=fof[u];
  ++fof[u];
  if(nf[ct+1]==0){
    nxt[ct+1]=nxt[ct];
    pv[nxt[ct]]=ct+1;
    nxt[ct]=ct+1;
    pv[ct+1]=ct;
  }
  if(nf[ct]==1){
    pv[ct+1]=pv[ct];
    nxt[pv[ct]]=ct+1;
  }
  --nf[ct];
  ++nf[ct+1];
}
void rm(in u){
  in ct=fof[u];
  assert(ct);
  --fof[u];
  if(nf[ct-1]==0){
    pv[ct-1]=pv[ct];
    nxt[pv[ct]]=ct-1;
    pv[ct]=ct-1;
    nxt[ct-1]=ct;
  }
  if(nf[ct]==1){
    nxt[ct-1]=nxt[ct];
    pv[nxt[ct]]=ct-1;
  }
  --nf[ct];
  ++nf[ct-1];
}
VI ans;
VI mar;
struct qr{
  in l,r,id;
  qr(in a=0, in b=0, in i=0){
    l=a;
    r=b;
    id=i;
  }
  bool operator<(const qr cp)const{
    return r<cp.r;
  }
};
void prb(vector<qr> bck){
  if(bck.empty())
    return;
  forn(i,mx){
    fof[i]=nf[i]=0;
    pv[i]=0;
    nxt[i]=mx;
  }
  nf[0]=mx;
  in cl=bck[0].l;
  in cr=bck[0].r;
  for(in i=cl;i<=cr;++i){
    ad(mar[i]);
  }
  ans[bck[0].id]=mkans();
  for(in j=1;j<sz(bck);++j){
    while(cl>bck[j].l){
      --cl;
      ad(mar[cl]);
    }
    while(cr<bck[j].r){
      ++cr;
      ad(mar[cr]);
    }
    while(cl<bck[j].l){
      rm(mar[cl]);
      ++cl;
    }
    ans[bck[j].id]=mkans();
  }
}
vector<vector<qr> > bck;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  pv.resize(mx+1);
  fof.resize(mx);
  nf.resize(mx);
  nxt.resize(mx+1,mx);
  in n,q;
  cin>>n;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  in s=1;
  while(s*s<n)
    ++s;
  cin>>q;
  ans.resize(q);
  bck.resize(s+5);
  in ta,tb;
  forn(i,q){
    cin>>ta>>tb;
    --ta;
    --tb;
    bck[ta/s].PB(qr(ta,tb,i));
  }
  forv(i,bck)
    sort(all(bck[i]));
  forv(i,bck)
    prb(bck[i]);
  forn(i,q)
    cout<<ans[i]<<"\n";
  return 0;
}