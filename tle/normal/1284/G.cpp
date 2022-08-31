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
#define SZ 55555
int T,n,m,id[55][55],an;
char s[55][55],op[55][55];
int M=0,fst[SZ],va[SZ],vb[SZ],nxt[SZ];
char* vc[SZ];
void ad_de(int a,int b,char* c)
{++M;nxt[M]=fst[a];fst[a]=M;va[M]=a;vb[M]=b;vc[M]=c;}
void adde(int a,int b,char* c){ad_de(a,b,c);ad_de(b,a,c);}
vector<int> ex;
int deg[SZ],dd[SZ];
bool ie[SZ];
int ff[SZ];
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
void uni(int a,int b)
{
	a=gf(a); b=gf(b);
	if(a!=b) ff[a]=b;
}
bool m1(const vector<bool> &v1)
{
	for(int i=1;i<=an;++i) ff[i]=0;
	for(int i=1;i<M;i+=2)
		if(!v1[i/2])
			uni(va[i],vb[i]);
	for(int i=1;i<=an;++i)
		if(gf(i)!=gf(1)) return 0;
	return 1;
}
bool m2(const vector<bool> &v1)
{
	for(auto e:ex) dd[e]=0;
	for(int i=1;i<M;i+=2)
		if(v1[i/2]) ++dd[va[i]],++dd[vb[i]];
	for(auto e:ex) if(dd[e]>deg[e]-2) return 0;
	return 1;
}
vector<bool> matroid_intersection(int n) {
  // maximize
  vector<bool> used(n);
  if (!m1(used) || !m2(used)) {
    return vector<bool>();
  }
  auto find_path = [&]() {
    vector<vector<int>> adj(n + 2);
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
      	used[i]=true;
		for(int i=1;i<=an;++i) ff[i]=0;
		for(int i=1;i<M;i+=2)
			if(!used[i/2])
				uni(va[i],vb[i]);
		for(int i=1;i<=an;++i) gf(i);
		for(int i=1;i<=an;++i)
			ff[i]=ff[i]?ff[i]:i;
		for(auto e:ex) dd[e]=0;
		for(int i=1;i<M;i+=2)
			if(used[i/2]) ++dd[va[i]],++dd[vb[i]];
		bool ok=1;
		for(auto e:ex) if(dd[e]>deg[e]-2) ok=0;
		if(ok) adj[n].push_back(i);
		bool good=1;
		for(int i=1;i<=an;++i)
			good&=ff[i]==ff[1];
        if(good) adj[i].push_back(n + 1);
        for (int j = 0; j < n; ++j) {
          if (used[j]&&j!=i) {
          	if(good||(ff[va[j*2+1]]!=ff[vb[j*2+1]]))
          		adj[i].push_back(j);
          }
        }
      	used[i]=false;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (used[i]) {
      	used[i]=false;
		for(auto e:ex) dd[e]=0;
		for(int i=1;i<M;i+=2)
			if(used[i/2]) ++dd[va[i]],++dd[vb[i]];
		bool ok=1;
		for(auto e:ex) if(dd[e]>deg[e]-2) ok=0;
		if(!ok)
		{
			used[i]=true;
			continue;
		}
        for (int j = 0; j < n; ++j) {
          if (!used[j]&&j!=i) {
          	bool oo=ok;
          	int e=j*2+1;
          	oo&=!(ie[va[e]]&&dd[va[e]]+1>deg[va[e]]-2);
          	oo&=!(ie[vb[e]]&&dd[vb[e]]+1>deg[vb[e]]-2);
          	if(oo) adj[i].push_back(j);
          }
        }
      	used[i]=true;
      }
    }
    vector<int> dist(n + 2, int(2e9));
    vector<bool> visit(n + 2);
    vector<int> pre(n + 2, -1);
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      visit[x] = false;
      for (auto y : adj[x]) {
        int cost = 0;
        if (y < n) {
          cost = used[y] ? 1 : -1;
        }
        if (dist[y] > dist[x] + cost) {
          dist[y] = dist[x] + cost;
          pre[y] = x;
          if (!visit[y]) {
            visit[y] = true;
            q.push(y);
          }
        }
      }
    }
    if (dist[n + 1] == int(2e9)) {
      return false;
    }
    for (int i = pre[n + 1]; i != n; i = pre[i]) {
      used[i] = !used[i];
    }
    return true;
  };
  while (find_path());
//  	cout<<"F\n";
  return used;
}

void sol()
{
	ex.clear();
	memset(id,0,sizeof id);
	memset(op,0,sizeof op);
	memset(ie,0,sizeof ie);
	scanf("%d%d",&n,&m); an=0; M=0;
	memset(fst,0,sizeof fst);
	for(int i=0;i<n;++i)
		scanf("%s",s[i]);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j) if(s[i][j]=='O')
		{
			id[i][j]=++an;
			if((i+j)%2==0&&(an!=1))
				ex.pb(an),ie[an]=1;
		}
	for(int i=0;i<2*n-1;++i)
		for(int j=0;j<2*m-1;++j) op[i][j]=' ';
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			op[i*2][j*2]=s[i][j];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j) if(s[i][j]=='O')
		{
			if(id[i][j+1])
				adde(id[i][j],id[i][j+1],&op[i*2][j*2+1]);
			if(id[i+1][j])
				adde(id[i][j],id[i+1][j],&op[i*2+1][j*2]);
		}
	}
	for(int i=1;i<=an;++i)
	{
		deg[i]=0;
		for(int e=fst[i];e;e=nxt[e]) ++deg[i];
	}
	for(auto e:ex)
		if(deg[e]<2)
		{
			puts("NO");
			return;
		}
//	cout<<"EZ"<<M/2<<"\n";
	auto g=matroid_intersection(M/2);
	int cn=0;
	for(int i=0;i<M/2;++i) cn+=!g[i];
	if(cn>=an)
	{
		puts("NO");
		return;
	}
	for(int i=0;i<M/2;++i)
		if(!g[i]) *vc[i*2+1]='O';
	puts("YES");
	for(int i=0;i<2*n-1;++i)
		puts(op[i]);
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}