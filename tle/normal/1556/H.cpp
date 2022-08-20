#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int k,d[SZ],w[55][55],D[SZ];
int id[55][55],cn,ff[55];
int gf(int x) {
	return (ff[x]==-1)?x:(ff[x]=gf(ff[x]));
}

vector<pii> ot;

//from https://blog.csdn.net/wxh010910/article/details/79450946

const int N = 5555;
const int inf = 0x3f3f3f3f;

int nn,dis[N], pre[N];
bool vis[N];
bitset<900> ins;
vector <int> adj[N];
priority_queue <pii> q;
typedef long long LL;
inline bool CheckX() {
	int dd[55];
	memset(dd,0,sizeof dd);
	for(int i=ins._Find_first();i<nn;i=ins._Find_next(i)) {
  	int x=ot[i].fi,y=ot[i].se;
  	if(x<k&&(++dd[x])+D[x]>d[x]) return 0;
  	if(y<k&&(++dd[y])+D[y]>d[y]) return 0;
  }
  return true;
}
int n_;
vector<pii> oe;
inline bool CheckY() {
	for(int i=0;i<n_;++i) ff[i]=-1;
	for(auto g: oe) {
  	int x=g.fi,y=g.se;
  	x=gf(x),y=gf(y);
  	if(x==y) return 0; ff[x]=y;
	}
	for(int i=ins._Find_first();i<nn;i=ins._Find_next(i)) {
  	int x=ot[i].fi,y=ot[i].se;
  	x=gf(x),y=gf(y);
  	if(x==y) return 0; ff[x]=y;
  }
  return 1;
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}
inline bool FindPath() {
  for (int i = 0; i < nn + 2; ++i) {
    adj[i].clear(), dis[i] = inf, vis[i] = false;
  }
//  cis.clear();
//  for (int i = 0; i < nn; ++i) if(ins[i]) cis.insert(i);
    for (int j = 0; j < nn; ++j) {
    if (ins[j]) {
		int dd[55];
		for(int i=0;i<n_;++i) ff[i]=-1;
		memset(dd,0,sizeof dd);
	for(auto g: oe) {
  	int x=g.fi,y=g.se;
  	x=gf(x),y=gf(y);
  	if(x==y) for(;;); ff[x]=y;
	}
		for(int i=ins._Find_first();i<nn;i=ins._Find_next(i)) if(i!=j) {
		  	int x=ot[i].fi,y=ot[i].se; ++dd[x];++dd[y];
		  	x=gf(x),y=gf(y);
			  if(x==y) for(;;);
			  ff[x]=y;
	  	}
	  for (int i = 0; i < nn; ++i) {
	    if (!ins[i]) {
	    	bool ox=1,oy;
	    	int x=ot[i].fi,y=ot[i].se; ++dd[x];++dd[y];
	    	ox&=x>=k||dd[x]+D[x]<=d[x];
	    	ox&=y>=k||dd[y]+D[y]<=d[y];
	    	--dd[x];--dd[y];
	    	oy=gf(x)!=gf(y);
//			ins[i]=!ins[i];ins[j]=!ins[j];
	          if (ox) {
	            adj[i].pb(j);
	          }
	          if (oy) {
	            adj[j].pb(i);
	          }
//			ins[i]=!ins[i];ins[j]=!ins[j];
        }
      }
    }
  }
  for (int i = 0; i < nn; ++i) {
    if (!ins[i]) {
      ins[i] = true;
//      cis.insert(i);
      if (CheckX()) {
        adj[i].pb(nn + 1);
      }
      if (CheckY()) {
        adj[nn].pb(i);
      }
      ins[i] = false;
//      cis.erase(i);
    }
  }
  dis[nn] = 0, q.push(mp(0, nn));
  while (!q.empty()) {
    int x = q.top().se;
    q.pop();
    if (vis[x]) {
      continue;
    }
    vis[x] = true;
    for (auto y : adj[x]) {
      if (CheckMin(dis[y], dis[x] - (ins[y] ? 1 : -1)*w[ot[y].fi][ot[y].se])) {
        q.push(mp(-dis[y], y)), pre[y] = x;
      }
    }
  }
  if (dis[nn + 1] == inf) {
    return false;
  }
  for (int i = pre[nn + 1]; i != nn; ins[i] = !ins[i], i = pre[i]);
  return true;
}
#define n n_


int main()
{
	ll ans=8e18;
//	n=50,k=1;
	cin>>n>>k;
	for(int i=0;i<k;++i) cin>>d[i];
	for(int i=0;i<k;++i)
		for(int j=i+1;j<k;++j) id[i][j]=cn++;
	for(int i=0;i<n;++i) {
		for(int j=i+1;j<n;++j)
//			w[i][j]=rand()%100+1,
			cin>>w[i][j],
			w[j][i]=w[i][j];
	}
	int cg=0;
	int c1=0;
	set<vector<int>> c2;
	vector<int> ss;
	for(int o=0;o<(1<<cn);++o) ss.pb(o);
	auto val=[&](int o) {
		ll tw=0;
		for(int i=0;i<k;++i)
			for(int j=i+1;j<k;++j) if(o&(1<<id[i][j])) {
				tw+=w[i][j];
			}
		return tw;
	};
	ot.clear();
	vector<pii> o0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j) if(i>=k||j>=k) {
			if(i<k||j<k);
			else o0.pb(pii(i,j));
		}
	sort(o0.begin(),o0.end(),[&](auto a,auto b) {
		return w[a.fi][a.se]<w[b.fi][b.se];
	});
	for(int i=0;i<n;++i) ff[i]=-1;
	ll oow=0;
	for(auto e:o0) {
		int x=gf(e.fi),y=gf(e.se);
		if(x==y) continue;
		ff[x]=y; ot.pb(e);
		oow+=w[x][y];
	}
//	cerr<<ot.size()<<"?\n";
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j) if(i>=k||j>=k) {
			if(i<k||j<k) ot.pb(pii(i,j));
		}
	nn=ot.size();
	ot.pb(pii(0,0));
	ot.pb(pii(0,0));
	ot.pb(pii(0,0));
//	cerr<<ot.size()<<" "<<oow<<"!\n";
//	cerr<<ot.size()<<"??\n";
	sort(ss.begin(),ss.end(),[&](int a,int b) {
		return val(a)<val(b);
	});
	for(auto o:ss) {
		for(int i=0;i<k;++i) ff[i]=-1,D[i]=0; oe.clear();
		int bad=0; ll tw=0;
		for(int i=0;i<k;++i)
			for(int j=i+1;j<k;++j) if(o&(1<<id[i][j])) {
				int x=gf(i),y=gf(j);
				if(x==y) bad=1; else ff[x]=y;
				tw+=w[i][j]; ++D[i],++D[j]; oe.pb(pii(i,j));
			}
		if(bad) continue;
		map<int,int> sig;
		vector<int> oo;
		for(int i=0;i<k;++i) {
			int w=gf(i);
			if(!sig.count(w)) sig[w]=i;
			oo.pb(sig[w]);
			oo.pb(D[i]);
		}
		if(c2.count(oo)) continue;
		++c1; c2.insert(oo);
		++cg;
//		cerr<<c1<<" "<<nn<<"\n";
		for(int i=0;i<k;++i) bad|=D[i]>d[i];
		if(bad) continue;
		for(int i=0;i<nn;++i) ins[i]=0;
		while (FindPath());
		int cnt=oe.size();
		for(int i=0;i<nn;++i) if(ins[i]) {
			cnt++; tw+=w[ot[i].fi][ot[i].se];
		}
		if(cnt!=n-1) continue;
		ans=min(ans,tw);
	}
//	cerr<<c1<<"but"<<c2.size()<<"?\n";
	cout<<ans<<"\n";
}