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
struct eg{
  in dest,c,f,rev;
};
struct flow{
  vector<bool> vtd;
  vector<vector<eg> > egs;
  vector<vector<in> > ept;
  vector<in> dtt;
  in n,s,t,tot,inf;
  void ini(in pn, in ps, in pt){
    n=pn;s=ps;t=pt;
    egs.resize(0);
    ept.resize(0);
    ept.resize(n,vector<in>(0));
    egs.resize(n,vector<eg>(0));
    dtt.resize(0);
    dtt.resize(n);
    tot=0;
    inf=1000000000000000LL;
    vtd.resize(n);
  }
  void add(in a, in b, in c1, in c2=0){
    eg ta,tb;
    ta.dest=b;
    tb.dest=a;
    ta.f=tb.f=0;
    ta.c=c1;
    tb.c=c2;
    ta.rev=egs[b].size();
    tb.rev=egs[a].size();
    egs[a].push_back(ta);
    egs[b].push_back(tb);
  }
  in doit(in u, in lim){
    if(u==t)
      return lim;
    in cfl=0;
    in dlm;
    in pl;
    while(cfl<lim && ept[u].size()>0){
      eg& tp=egs[u][ept[u].back()];
      dlm=lim-cfl;
      if(dlm>tp.c-tp.f)
	dlm=tp.c-tp.f;
      pl=doit(tp.dest,dlm);
      tp.f+=pl;
      egs[tp.dest][tp.rev].f-=pl;
      if(pl<dlm || dlm==0)
	ept[u].pop_back();
      cfl+=pl;
    }
    return cfl;
  }
  in dinic(){
    while(true){
      forn(i,n){
	ept[i].resize(0);
	dtt[i]=inf;
      }
      queue<in> q;
      dtt[t]=0;
      q.push(t);
      while(!q.empty()){
	in u=q.front();
	q.pop();
	forv(i,egs[u]){
	  eg& tp=egs[u][i];
	  if(dtt[tp.dest]<inf)
	    continue;
	  if(egs[tp.dest][tp.rev].c==egs[tp.dest][tp.rev].f)
	    continue;
	  dtt[tp.dest]=dtt[u]+1;
	  q.push(tp.dest);
	}
      }
      forn(i,n)
	vtd[i]=0;
      vtd[s]=1;
      q.push(s);
      while(!q.empty()){
	in u=q.front();
	q.pop();
	forv(i,egs[u]){
	  eg& tp=egs[u][i];
	  if(dtt[tp.dest]+1>dtt[u])
	    continue;
	  if(tp.f==tp.c)
	    continue;
	  ept[u].push_back(i);
	  if(!vtd[tp.dest])
	    q.push(tp.dest);
	  vtd[tp.dest]=1;
	}
      }
      in pl=doit(s,inf);
      if(pl==0)
	break;
      tot+=pl;
    }
    return tot;
  }
};
flow tfl;
VI mar;
VVI megs;
in cnt(in n, in a){
  in r=0;
  while(n%a==0){
    ++r;
    n/=a;
  }
  return r;
}
in bfl(in a){
  in n=sz(mar)+2;
  in s=n-1;
  in t=n-2;
  tfl.ini(n,s,t);
  forv(i,mar){
    if(i%2==0)
      tfl.add(s,i,cnt(mar[i],a));
    else
      tfl.add(i,t,cnt(mar[i],a));
  }
  forv(i,megs)
    tfl.add(megs[i][0],megs[i][1],1000000);
  return tfl.dinic();
}
set<in> pfc;
void adfc(in a){
  for(in i=2;i*i<=a;++i){
    if(a%i)
      continue;
    pfc.insert(i);
    while(a%i==0)
      a/=i;
  }
  if(a!=1)
    pfc.insert(a);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  mar.resize(n);
  megs.resize(m,VI(2));
  forn(i,n){
    cin>>mar[i];
    adfc(mar[i]);
  }
  forn(i,m){
    forn(z,2){
      cin>>megs[i][z];
      --megs[i][z];
    }
    if(megs[i][0]%2)
      swap(megs[i][0],megs[i][1]);
  }
  in sm=0;
  fors(i,pfc)
    sm+=bfl(*i);
  cout<<sm<<endl;
  return 0;
}