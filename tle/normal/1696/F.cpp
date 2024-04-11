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
int T,n,cc[105],v,vis[105];
char st[105][105][105];
vector<int> adj[105];
void dfs(int x,int h) {
	assert(!vis[x]);
	vis[x]=1;++v;
	//dis(x,h)=dis(x,u)
	for(int u=1;u<=n;++u)
		if(h==u||st[min(u,h)][max(u,h)][x]=='1')
			if(!vis[u])
				adj[x].pb(u),adj[u].pb(x),
				dfs(u,x);
}
int dis[105][105],*D;
void dfs2(int x,int f=0) {
	D[x]=D[f]+1;
	for(auto b:adj[x]) if(b!=f) {
		dfs2(b,x);
	}
}
int xx[105];
inline int C2(int x) {return x*(x-1)/2;}
bool chk() {
	for(int i=1;i<=n;++i) {
		D=dis[i]; dfs2(i);
	}
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=n;++j) xx[j]=0;
		for(int j=1;j<=n;++j) xx[dis[i][j]]++;
		int sb=0;
		for(int j=1;j<=n;++j) sb+=C2(xx[j]);
//		cerr<<cc[i]<<","<<sb<<"!\n";
		if(sb!=cc[i]) return 0;
	}
	for(int i=1;i<n;++i)
		for(int j=i+1;j<n;++j)
			for(int k=1;k<=n;++k)
				if((st[i][j][k]=='1')!=(dis[i][k]==dis[j][k]))
					return 0;
//	cerr<<"maybe?\n";
	return 1;
}
void sol() {
	cin>>n;
	for(int i=1;i<=n;++i)cc[i]=0;
	for(int i=1;i<n;++i) {
		for(int j=1;j<=n-i;++j) {
			cin>>(st[i][i+j]+1);
			for(int k=1;k<=n;++k)
				cc[k]+=st[i][i+j][k]=='1';
		}
	}
	for(int i=2;i<=n;++i) {
		for(int j=1;j<=n;++j) vis[j]=0,adj[j].clear();
		v=0;
		dfs(i,1);
		if(v!=n) continue;
		if(chk()) {
			puts("Yes");
			for(int i=1;i<=n;++i)
				for(auto t:adj[i]) if(i<t) printf("%d %d\n",i,t); 
			return;
		}
	}
	puts("No");
}
int main() {
    cin.tie(0);ios::sync_with_stdio(0);
	cin>>T;
	while(T--) sol();
}