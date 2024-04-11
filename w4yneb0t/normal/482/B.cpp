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
in n,m;
struct lim{
  in l,r,q;
};
struct evt{
  in id,typ,loc;
  evt(in a=0, in b=0, in c=0){id=a;typ=c;loc=b;}
  bool operator<(const evt cp)const{
    if(loc!=cp.loc)
      return loc<cp.loc;
    return typ<cp.typ;
  }
};
vector<lim> lims;
vector<evt> evts;
vector<in> sol;
vector<in> act,lsn;
in p2(in& a){
  return (1LL<<a);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m;
  lims.resize(m);
  forn(i,m){
    cin>>lims[i].l>>lims[i].r>>lims[i].q;
    lims[i].l--;
    lims[i].r--;
    evts.PB(evt(i,lims[i].l,0));
    evts.PB(evt(i,lims[i].r,1));
  }
  in mx=30;
  sort(all(evts));
  act.resize(mx,0);
  lsn.resize(mx,-1);
  in nev=0;
  in cnb=0;
  sol.resize(n);
  in tp;
  bool ok=1;
  forn(cloc,n){
    while(nev<2*m && evts[nev].loc<=cloc && evts[nev].typ==0){
      tp=lims[evts[nev].id].q;
      forn(i,mx){
	if(tp&p2(i)){
	  cnb|=p2(i);
	  act[i]++;
	}
      }
      nev++;
    }
    sol[cloc]=cnb;
    forn(i,mx){
      if(!(cnb&p2(i)))
	lsn[i]=cloc;
    }
    while(nev<2*m && evts[nev].loc<=cloc){
      tp=lims[evts[nev].id].q;
      forn(i,mx){
	if(!(tp&p2(i))){
	  if(lsn[i]<lims[evts[nev].id].l)
	    ok=0;
	}
	else{
	  act[i]--;
	  if(act[i]==0)
	    cnb^=p2(i);
	}
      }
      nev++;
    }
  }
  if(!ok){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES\n";
    forn(i,n)
      cout<<sol[i]<<" ";
    cout<<"\n";
  }
  return 0;
}