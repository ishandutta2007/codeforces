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
    inf=1e9;
    vtd.resize(n);
  }
  void add(in a, in b, in c1, in c2=0){
    eg ta,tb;
    ta.dest=b;
    tb.dest=a;
    ta.f=tb.f=0;
    ta.c=c1;
    tb.c=c2;
    ta.rev=egs[b].size()+(a==b);
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
VVI egs,egc;
VI cap;
VI de;
VVI ccs;
VI vis;
in n;
in fu,fv;
VI nx;
VI tpc;
bool fnd(in u){
  if(vis[u])
    return 0;
  vis[u]=1;
  if(u==fv)
    return 1;
  in tp;
  forv(i,egs[u]){
    tp=egs[u][i];
    if(u==fu && tp==fv)
      continue;
    if(fnd(tp)){
      nx[u]=tp;
      tpc.PB(egc[u][i]);
      return 1;
    }
  }
  return 0;
}
bool fc(in u, in v, in c){
  vis.resize(n);
  nx.resize(n);
  forn(i,n){
    nx[i]=-1;
    vis[i]=0;
  }
  fu=u;
  fv=v;
  bool tr=fnd(u);
  if(!tr)
    return 0;
  nx[v]=u;
  tpc.PB(c);
  ccs.PB(tpc);
  tpc.resize(0);
  forv(i,egs){
    in t=0;
    forv(j,egs[i]){
      if(i==nx[egs[i][j]] || egs[i][j]==nx[i])
	continue;
      egs[i][t]=egs[i][j];
      egc[i][t++]=egc[i][j];
    }
    egs[i].resize(t);
    egc[i].resize(t);
  }
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>n>>m;
  cap.resize(m);
  egs.resize(n);
  egc.resize(n);
  in ta,tb,tc;
  forn(z,m){
    cin>>ta>>tb>>tc;
    --ta;
    --tb;
    --tc;
    ++cap[tc];
    egs[ta].PB(tb);
    egs[tb].PB(ta);
    egc[ta].PB(tc);
    egc[tb].PB(tc);
  }
  forn(i,n){
    forv(j,egs[i]){
      if(egs[i][j]<i)
	continue;
      if(fc(i,egs[i][j],egc[i][j]))
	j=-1;
    }
  }
  de.resize(m);
  in tn=0;
  forv(i,cap){
    if(cap[i])
      de[i]=tn++;
    else
      de[i]=-1;
  }
  in cc=sz(ccs);
  in s=cc+tn;
  in t=s+1;
  tfl.ini(t+1,s,t);
  forn(i,m){
    if(de[i]!=-1)
      tfl.add(s,de[i],cap[i]-1);
  }
  forv(i,ccs){
    tfl.add(i+tn,t,1);
    forv(j,ccs[i])
      tfl.add(de[ccs[i][j]],i+tn,1);
  }
  cout<<tn-(cc-tfl.dinic())<<endl;
  return 0;
}