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
VI a,b,g;
VI f,c;
VI crit;
void rassert(bool d){
  if(!d){
    forn(z,1e6){
      if(z>1e4)
	z-=1e3;
    }
  }
}
VVI regs,egid;
VI viscyc;
bool inccyc(in cur, in gol){
  viscyc[cur]=1;
  if(cur==gol)
    return 1;
  forv(i,regs[cur]){
    if(viscyc[regs[cur][i]])
      continue;
    if(inccyc(regs[cur][i],gol)){
      ++f[egid[cur][i]];
      return 1;
    }
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,s,t;
  cin>>n>>m>>s>>t;
  --s;
  --t;
  regs.resize(n);
  egid.resize(n);
  tfl.ini(n,s,t);
  in ta,tb,tg;
  forn(z,m){
    cin>>ta>>tb>>tg;
    --ta;
    --tb;
    regs[ta].PB(tb);
    egid[ta].PB(z);
    a.PB(ta);
    b.PB(tb);
    g.PB(tg);
    if(tg==1){
      tfl.add(ta,tb,1,1e6);
    }
    else{
      tfl.add(ta,tb,1e6);
    }
  }
  f.resize(m);
  c.resize(m);
  forn(i,m){
    f[i]=0;
    c[i]=1e6;
  }
  crit.resize(m,0);
  in res=tfl.dinic();
  rassert(res<1e5);
  cout<<res<<endl;
  VI vis(n,0);
  in u=s;
  vis[u]=1;
  queue<in> q;
  q.push(u);
  while(!q.empty()){
    u=q.front();
    q.pop();
    for(auto eg:tfl.egs[u]){
      if(vis[eg.dest])
	continue;
      if(eg.f==eg.c)
	continue;
      vis[eg.dest]=1;
      q.push(eg.dest);
    }
  }
  in totcrit=0;
  forn(i,m){
    if(vis[a[i]] && !vis[b[i]]){
      rassert(g[i]==1);
      crit[i]=1;
      ++totcrit;
    }
  }
  rassert(totcrit==res);
  VI pv(n,-1);
  VI pveg(n,-1);
  VI nxt(n,-1);
  VI nxteg(n,-1);
  VI vispv(n,0);
  VI visnxt(n,0);
  pv[s]=s;
  nxt[t]=t;
  vispv[s]=visnxt[t]=1;
  forn(z,n+9){
    forn(i,m){
      if(!g[i])
	continue;
      if(visnxt[a[i]]==0 && visnxt[b[i]]==1){
	visnxt[a[i]]=1;
	nxt[a[i]]=b[i];
	nxteg[a[i]]=i;
      }
      if(vispv[a[i]]==1 && vispv[b[i]]==0){
	vispv[b[i]]=1;
	pv[b[i]]=a[i];
	pveg[b[i]]=i;
      }
    }
  }
  forn(i,m){
    if(g[i]==1){
      ++f[i];
      if(vispv[a[i]] && visnxt[b[i]]){
	in ceg=a[i];
	while(ceg!=s){
	  ++f[pveg[ceg]];
	  ceg=pv[ceg];
	}
	ceg=b[i];
	while(ceg!=t){
	  ++f[nxteg[ceg]];
	  ceg=nxt[ceg];
	}
      }
      else{
	viscyc.resize(n);
	forn(z,n)
	  viscyc[z]=0;
	inccyc(b[i],a[i]);
      }
    }
  }
  forn(i,m){
    if(crit[i])
      c[i]=f[i];
  }
  forn(i,m){
    rassert(f[i]<=c[i]);
    rassert(crit[i]==(f[i]==c[i]));
    rassert(g[i]==(f[i]>0));
    rassert(f[i]>=0);
    cout<<f[i]<<" "<<c[i]<<endl;
  }
  return 0;
}