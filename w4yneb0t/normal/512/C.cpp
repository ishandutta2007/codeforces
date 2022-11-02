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
VI isp;
VVI tbl;
VI vis;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in s=n;
  in t=n+1;
  tfl.ini(n+2,s,t);
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  isp.resize(100000,1);
  isp[0]=isp[1]=0;
  for(in i=2;i<sz(isp);++i){
    for(in j=2*i;j<sz(isp);j+=i)
      isp[j]=0;
  }
  forn(i,n){
    if(mar[i]%2)
      tfl.add(i,t,2);
    else{
      tfl.add(s,i,2);
      forn(j,n){
	if(isp[mar[i]+mar[j]])
	  tfl.add(i,j,1);
      }
    }
  }
  if(tfl.dinic()!=n){
    cout<<"Impossible\n";
    return 0;
  }
  vis.resize(n,0);
  forn(i,n){
    if(vis[i])
      continue;
    VI cr;
    in u=i;
    bool ok=1;
    while(ok){
      ok=0;
      vis[u]=1;
      cr.PB(u);
      forv(j,tfl.egs[u]){
	if(tfl.egs[u][j].f && tfl.egs[u][j].dest!=t && tfl.egs[u][j].dest!=s && !vis[tfl.egs[u][j].dest]){
	  u=tfl.egs[u][j].dest;
	  ok=1;
	  break;
	}
      }
    }
    tbl.PB(cr);
  }
  cout<<sz(tbl)<<endl;
  forv(i,tbl){
    cout<<sz(tbl[i]);
    forv(j,tbl[i])
      cout<<" "<<(tbl[i][j]+1);
    cout<<endl;
  }
  return 0;
}