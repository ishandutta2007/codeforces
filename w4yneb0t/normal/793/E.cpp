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
const in mx=5009;
VI p;
VI stsz;
VVI cd;
VI genknap(VI s){
  VI r(mx,0);
  r[0]=1;
  forv(i,s){
    for(in j=mx-s[i]-1;j>=0;--j)
      r[j+s[i]]|=r[j];
  }
  return r;
}
VI genup(in a){
  VI hv;
  in pva;
  while(1){
    pva=a;
    a=p[a];
    if(a==0)
      break;
    forv(i,cd[a]){
      if(cd[a][i]==pva)
	continue;
      hv.PB(stsz[cd[a][i]]);
    }
  }
  return genknap(hv);
}
in gentotint(in a){
  while(p[a]!=0)
    a=p[a];
  return stsz[a];
}
in ghf;
VI genpr(VI ta, VI tb, in totintc){
  VI avb(mx,0);
  forv(i,ta){
    if(!ta[i])
      continue;
    forv(j,tb){
      if(!tb[j])
	continue;
      if(i+j+totintc>ghf)
	continue;
      avb[ghf-(i+j+totintc)]=1;
    }
  }
  return avb;
}
bool isok(VI totkp, VI alwd){
  forv(i,totkp){
    if(totkp[i] && i<sz(alwd) && alwd[i])
      return 1;
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in a,b,c,d;
  in n;
  cin>>n;
  p.resize(n);
  p[0]=0;
  stsz.resize(n);
  cd.resize(n);
  cin>>a>>b>>c>>d;
  --a;
  --b;
  --c;
  --d;
  for(in i=1;i<n;++i){
    cin>>p[i];
    --p[i];
    cd[p[i]].PB(i);
  }
  for(in i=n-1;i>=1;--i){
    if(sz(cd[i])==0)
      ++stsz[i];
    stsz[p[i]]+=stsz[i];
  }
  in totlfs=stsz[0];
  if(totlfs%2==1){
    cout<<"NO"<<endl;
    return 0;
  }
  ghf=(totlfs-2)/2;
  VI ta=genup(a);
  VI tb=genup(b);
  VI tc=genup(c);
  VI td=genup(d);
  in totinta=gentotint(a);
  in totintb=gentotint(b);
  in totintc=gentotint(c);
  in totintd=gentotint(d);
  VI alwdab=genpr(ta,tb,totintc);
  VI alwdcd=genpr(tc,td,totintb);
  multiset<in> up0;
  forv(i,cd[0]){
    up0.insert(stsz[cd[0][i]]);
  }
  up0.erase(up0.find(totinta));
  up0.erase(up0.find(totintb));
  up0.erase(up0.find(totintc));
  up0.erase(up0.find(totintd));
  VI ss;
  fors(i,up0)
    ss.PB(*i);
  VI totkp=genknap(ss);
  bool okab=isok(totkp,alwdab);
  bool okcd=isok(totkp,alwdcd);
  if(okab && okcd){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}