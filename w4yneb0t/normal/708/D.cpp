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
const double eps=0.0000001;
struct eg{
  in dest,c,f,rev;
  double cost;
};
struct flow{
  vector<bool> vtd;
  vector<vector<eg> > egs;
  vector<vector<in> > ept;
  vector<in> dtt;
  in n,s,t,tot,inf;
  double totcost;
  void adegfl(eg& g, in c){
    g.f+=c;
    totcost+=c*g.cost;
    egs[g.dest][g.rev].f-=c;
    totcost-=c*egs[g.dest][g.rev].cost;
  }
  void adfl(in a, in b, in c){
    adegfl(egs[a][b],c);
  }
  in feg(in a, in b){
    forv(i,egs[a])
      if(egs[a][i].dest==b)
	return i;
    assert(0);
    return -1;
  }
  void ini(in pn, in ps, in pt){
    totcost=0;
    n=pn;s=ps;t=pt;
    egs.resize(0);
    ept.resize(0);
    ept.resize(n,vector<in>(0));
    egs.resize(n,vector<eg>(0));
    dtt.resize(0);
    dtt.resize(n);
    tot=0;
    inf=1000000000LL;
    vtd.resize(n);
  }
  void add(in a, in b, double cst, in c1, in c2=0){
    assert(a>=0);
    assert(b>=0);
    assert(a<n);
    assert(b<n);
    eg ta,tb;
    ta.dest=b;
    tb.dest=a;
    ta.f=tb.f=0;
    ta.c=c1;
    tb.c=c2;
    ta.cost=cst*0.5;
    tb.cost=-cst*0.5;
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
      adegfl(tp,pl);
      if(pl<dlm || dlm==0)
	ept[u].pop_back();
      cfl+=pl;
    }
    return cfl;
  }
  in dinic(){
    while(true){
      for(in i=0;i<n;i++){
	ept[i].resize(0);
	dtt[i]=inf;
      }
      queue<in> q;
      dtt[t]=0;
      q.push(t);
      while(!q.empty()){
	in u=q.front();
	q.pop();
	for(in i=0;i<in(egs[u].size());i++){
	  eg& tp=egs[u][i];
	  if(dtt[tp.dest]<inf)
	    continue;
	  if(egs[tp.dest][tp.rev].c==egs[tp.dest][tp.rev].f)
	    continue;
	  dtt[tp.dest]=dtt[u]+1;
	  q.push(tp.dest);
	}
      }
      for(in i=0;i<n;i++)
	vtd[i]=0;
      vtd[s]=1;
      q.push(s);
      while(!q.empty()){
	in u=q.front();
	q.pop();
	for(in i=0;i<in(egs[u].size());i++){
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
  double rct(in st){
    vector<double> bds(n,inf);
    VI prv(n,-1);
    VI preg(n,-1);
    VI mfto(n,0);
    mfto[st]=inf;
    bds[st]=0;
    in pfl;
    forn(z,n+5){
      forn(i,n){
	forv(j,egs[i]){
	  pfl=min(mfto[i],egs[i][j].c-egs[i][j].f);
	  if(pfl==0)continue;
	  if(bds[egs[i][j].dest]>bds[i]+egs[i][j].cost+eps){
	    prv[egs[i][j].dest]=i;
	    preg[egs[i][j].dest]=j;
	    mfto[egs[i][j].dest]=pfl;
	    bds[egs[i][j].dest]=bds[i]+egs[i][j].cost;
	  }
	}
      }
    }
    if(bds[st]>-eps)return 0;
    in fts=inf;
    double tcg=totcost;
    in u=st;
    in v;
    VI vis(n,0);
    while(!vis[u]){
      vis[u]=1;
      v=u;
      u=prv[u];
    }
    st=u;
    vis=VI(n,0);
    u=st;
    while(!vis[u]){
      vis[u]=1;
      v=u;
      u=prv[u];
      fts=min(fts,egs[u][preg[v]].c-egs[u][preg[v]].f);
    }
    assert(fts!=0);
    vis=VI(n,0);
    while(!vis[u]){
      vis[u]=1;
      v=u;
      u=prv[u];
      adfl(u,preg[v],fts);
    }
    tcg-=totcost;
    return tcg;
  }
  double mincst(){
    double fsf=eps+1;
    while(fsf>eps){
      fsf=0;
      forn(i,n){
	fsf=max(fsf,rct(i));
      }
    }
    return totcost;
  }
};
flow tfl;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  tfl.ini(n,0,n-1);
  in csf=0;
  in ta,tb,tc,tf;
  const in inf=1e9;
  tfl.add(n-1,0,0,inf);
  forn(z,m){
    cin>>ta>>tb>>tc>>tf;
    --ta;
    --tb;
    csf+=tf;
    tfl.add(ta,tb,-1,min(tc,tf));
    tfl.add(ta,tb,2,inf);
    if(tc<tf)
      tfl.add(ta,tb,0,tf-tc);
    if(tf<tc)
      tfl.add(ta,tb,1,tc-tf);
  }
  double tp=-tfl.mincst();
  in tr=tp+0.5;
  cout<<csf-tr<<endl;
  return 0;
}