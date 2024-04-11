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
VI mdf;
struct unifnd{
  VI ht,pr;
  in fnd(in a){
    in ta=a;
    while(a!=pr[a])a=pr[a];
    in tt=ta;
    while(ta!=a){
      tt=pr[ta];
      pr[ta]=a;
      ta=tt;
    }
    return a;
  }
  void uni(in a, in b){
    mdf.PB(a);
    mdf.PB(b);
    a=fnd(a);
    b=fnd(b);
    if(a==b)return;
    if(ht[b]<ht[a])swap(a,b);
    pr[a]=b;
    ht[b]+=(ht[a]==ht[b]);
  }
  void ini(in n){
    ht.resize(n);
    pr.resize(n);
    forn(i,n){
      ht[i]=0;
      pr[i]=i;
    }
  }
};
VVI clq;
VI lrs;
unifnd tfd;
in cps;
void mkl(vector<pair<in,in> >& v){
  forv(i,v){
    tfd.uni(v[i].first,v[i].second);
  }
  forv(i,mdf){
    if(lrs[mdf[i]]==cps)
      continue;
    lrs[mdf[i]]=cps;
    clq[mdf[i]].PB(tfd.fnd(mdf[i])+cps*100009);
  }
  forv(i,mdf){
    tfd.pr[mdf[i]]=mdf[i];
    tfd.ht[mdf[i]]=0;
  }
  mdf.clear();
}
vector<vector<pair<in,in> > > ecl;
map<pair<in,in>, in> ans;
in sml(const VI& a, const VI& b){
  if(sz(a)>sz(b))
    return sml(b,a);
  if(sz(a)==0)
    return 0;
  if(sz(b)/sz(a)<9){
    in tb=sz(b);
    in ta=sz(a);
    in cb=0;
    in ca=0;
    in r=0;
    while(cb<tb && ca<ta){
      if(b[cb]<a[ca]){
	++cb;
	continue;
      }
      if(b[cb]==a[ca]){
	++r;
	++cb;
      }
      ++ca;
    }
    return r;
  }
  in r=0;
  forv(i,a){
    if(*(lower_bound(all(b),a[i]))==a[i])
      ++r;
  }
  return r;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  tfd.ini(n);
  clq.resize(n);
  ecl.resize(m+9);
  in ta,tb,tc;
  lrs.resize(n,-2);
  forn(z,m){
    cin>>ta>>tb>>tc;
    --ta;
    --tb;
    ecl[tc].PB(MP(ta,tb));
  }
  cps=0;
  forv(i,ecl){
    ++cps;
    mkl(ecl[i]);
  }
  forv(i,clq)
    sort(all(clq[i]));
  in q;
  cin>>q;
  forn(z,q){
    cin>>ta>>tb;
    --ta;
    --tb;
    if(ans.find(MP(ta,tb))==ans.end()){
      ans[MP(ta,tb)]=sml(clq[ta],clq[tb]);
    }
    cout<<ans[MP(ta,tb)]<<"\n";
  }
  return 0;
}