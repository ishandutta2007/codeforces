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
in sm=0;
struct trmp{
  map<int,in> tpp;
  int ts;
};
vector<trmp> trps;
in nwg=1;
in n,mdl;
VI mar;
VI smup;
VI wtg;
in nrm(const in& a){
  while(a>=mdl)
    return a-mdl;
  while(a<0)
    return a+mdl;
  return a;
}
map<int,in>::iterator tpit;
in acc(map<int,in>& tp, in ind){
  tpit=tp.find(ind);
  if(tpit!=tp.end())
    return tpit->second;
  return 0;
}
VI rend,lend;
void mkr(in loc){
  in crt=mar[loc];
  in lfp=wtg[loc-1];
  in rtp=wtg[loc+1];
  if(lfp==0 && rtp==0){
    trps.resize(++nwg);
    trps.back().tpp[smup[loc]]++;
    trps.back().tpp[smup[loc-1]]++;
    trps.back().ts=sz(trps.back().tpp);
    lend[loc]=rend[loc]=loc;
    wtg[loc]=nwg-1;
    sm++;
    return;
  }
  if(trps[lfp].ts>trps[rtp].ts){
    fors(it,trps[rtp].tpp){
      sm+=it->second*acc(trps[lfp].tpp,nrm(it->first-crt));
    }
    fors(it,trps[rtp].tpp){
      trps[lfp].tpp[it->first]+=it->second;
    }
    if(rtp==0){
      sm+=acc(trps[lfp].tpp,nrm(smup[loc]-crt));
      rend[lend[loc-1]]=loc;
      lend[loc]=lend[loc-1];
      wtg[loc]=lfp;
      trps[lfp].tpp[smup[loc]]++;
    }
    else{
      rend[lend[loc-1]]=rend[loc+1];
      lend[rend[loc+1]]=lend[loc-1];
      wtg[rend[loc+1]]=lfp;
    }
    trps[lfp].ts=sz(trps[lfp].tpp);
  }
  else{
    fors(it,trps[lfp].tpp){
      sm+=it->second*acc(trps[rtp].tpp,nrm(it->first+crt));
    }
    fors(it,trps[lfp].tpp){
      trps[rtp].tpp[it->first]+=it->second;
    }
    if(lfp==0){
      sm+=acc(trps[rtp].tpp,nrm(crt+smup[loc-1]));
      lend[rend[loc+1]]=loc;
      rend[loc]=rend[loc+1];
      wtg[loc]=rtp;
      trps[rtp].tpp[smup[loc-1]]++;
    }
    else{
      lend[rend[loc+1]]=lend[loc-1];
      rend[lend[loc-1]]=rend[loc+1];
      wtg[lend[loc-1]]=rtp;
      wtg[loc]=rtp;
    }
    trps[rtp].ts=sz(trps[rtp].tpp);
  }
}
struct tpst{
  in id, s;
  bool operator<(const tpst cp)const{
    if(s!=cp.s)
      return s<cp.s;
    return id<cp.id;
  }
};
vector<tpst> pps;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>mdl;
  pps.resize(n);
  mar.resize(n+2,0);
  smup.resize(n+2,0);
  rend.resize(n+2);
  lend=rend;
  lend[0]=rend[0]=0;
  lend[n+1]=rend[n+1]=n+1;
  forn(i,n){
    cin>>mar[i+1];
    pps[i].id=i+1;
    pps[i].s=mar[i+1];
    mar[i+1]%=mdl;
    smup[i+1]=smup[i]+mar[i+1];
    smup[i+1]%=mdl;
  }
  smup[n+1]=smup[n];
  trps.resize(1);
  wtg.resize(n+2,0);
  sort(all(pps));
  forv(i,pps){
    mkr(pps[i].id);
  }
  cout<<sm-n<<endl;
  return 0;
}