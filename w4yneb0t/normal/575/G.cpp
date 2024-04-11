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
VVI egs,egl;
VVI nxt;
VI dts;
VI opt;
queue<in> q;
VI ans;
void gog(VI isg){
  if(isg[0]==0)return;
  in td=dts[isg[0]];
  in bst=100;
  forv(i,isg){
    forv(j,egs[isg[i]]){
      if(dts[egs[isg[i]][j]]==td-1)
	bst=min(bst,egl[isg[i]][j]);
    }
  }
  VI nuisg;
  in tt;
  forv(i,isg){
    forv(j,egs[isg[i]]){
      tt=egs[isg[i]][j];
      if(dts[tt]==td-1 && bst==egl[isg[i]][j]){
	nxt[tt].PB(isg[i]);
	if(opt[tt])continue;
	opt[tt]=1;
	nuisg.PB(tt);
      }
    }
  }
  ans.PB(bst);
  gog(nuisg);
}
VI dte;
const in inf=1000009;
void gend(in u, VI& mts, bool only0){
  mts=VI(sz(egs),inf);
  mts[u]=0;
  q.push(u);
  in tt;
  while(!q.empty()){
    u=q.front();
    q.pop();
    forv(i,egs[u]){
      if(only0 && egl[u][i]!=0)continue;
      tt=egs[u][i];
      if(mts[tt]<=mts[u]+1)continue;
      mts[tt]=mts[u]+1;
      q.push(tt);
    }
  }
}
VI prv;
VI tps;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  egs=egl=VVI(n);
  nxt.resize(n);
  opt=VI(n,0);
  in ta,tb,tw;
  forn(i,m){
    cin>>ta>>tb>>tw;
    egs[ta].PB(tb);
    egl[ta].PB(tw);
    egs[tb].PB(ta);
    egl[tb].PB(tw);
  }
  gend(0,dts,0);
  gend(n-1,dte,1);
  in bsd=inf;
  forn(i,n)
    if(dte[i]!=inf)
      bsd=min(bsd,dts[i]);
  forn(i,n)
    if(dte[i]!=inf && dts[i]==bsd)
      tps.PB(i);
  gog(tps);
  assert(sz(ans)==bsd);
  forv(i,ans)
    cout<<ans[i];
  if(sz(ans)==0)
    cout<<"0";
  cout<<"\n";
  prv=VI(n,-1);
  assert(q.empty());
  q.push(0);
  in u;
  in tt;
  prv[0]=0;
  while(!q.empty()){
    u=q.front();q.pop();
    forv(i,nxt[u]){
      tt=nxt[u][i];
      if(prv[tt]==-1){
	prv[tt]=u;
	q.push(tt);
      }
    }
  }
  in bst=inf;
  in bsl=-1;
  forn(i,n){
    if(dte[i]!=inf && prv[i]!=-1){
      if(dte[i]<bst){
	bst=dte[i];
	bsl=i;
      }
    }
  }
  assert(bst<inf);
  cout<<bsd+bst+1<<"\n";
  ans.clear();
  u=bsl;
  while(u!=n-1){
    forv(i,egs[u]){
      if(egl[u][i]==0 && dte[egs[u][i]]+1==dte[u]){
	u=egs[u][i];
	ans.PB(u);
	break;
      }
    }
  }
  reverse(all(ans));
  u=bsl;
  while(u!=0){
    ans.PB(u);
    u=prv[u];
  }
  ans.PB(0);
  reverse(all(ans));
  forv(i,ans)
    cout<<ans[i]<<" ";
  cout<<"\n";
  return 0;
}