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
int T,n,a[SZ],l1[SZ],r1[SZ],l2[SZ],r2[SZ];
int st[SZ],sn;
void build(int*l,int*r) {
	a[0]=a[n+1]=1e9;
	st[sn=1]=0;
	for(int i=1;i<=n;++i) {
		while(a[st[sn]]<a[i]) --sn;
		l[i]=st[sn]+1; st[++sn]=i;
	}
	st[sn=1]=n+1;
	for(int i=n;i>=1;--i) {
		while(a[st[sn]]<a[i]) --sn;
		r[i]=st[sn]-1; st[++sn]=i;
	}
}
bool vis[SZ];
#define M 262144
vector<int> L2[SZ],R2[SZ],L1[SZ],R1[SZ];
void put(vector<int>*v,int l,int r,int u) {
	if(l>r) return;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1) {
		if(~l&1) v[l^1].pb(u);
		if(r&1) v[r^1].pb(u);
	}
}
int qs[SZ],h,t,d[SZ];
void aug(int x) {
	auto cons=[&](int o) {
		if(!vis[o])
			vis[o]=1,d[o]=d[x]+1,qs[t++]=o;
	};
//	cerr<<"AUGS\n";
	{
	int w=x+M;
	while(w) {
		auto&v=L2[w]; int o;
		while(!v.empty()&&(o=v.back())<=r1[x]) {
			cons(o); v.pop_back();
		}
		w>>=1;
	}
	}
	{
	int w=x+M;
	while(w) {
		auto&v=L1[w]; int o;
		while(!v.empty()&&(o=v.back())<=r2[x]) {
			cons(o); v.pop_back();
		}
		w>>=1;
	}
	}
	{
	int w=x+M;
	while(w) {
		auto&v=R2[w]; int o;
		while(!v.empty()&&(o=v.back())>=l1[x]) {
			cons(o); v.pop_back();
		}
		w>>=1;
	}
	}
	{
	int w=x+M;
	while(w) {
		auto&v=R1[w]; int o;
		while(!v.empty()&&(o=v.back())>=l2[x]) {
			cons(o); v.pop_back();
		}
		w>>=1;
	}
	}
//	cerr<<"AUGF\n";
}
void sol() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i) vis[i]=0;
	build(l1,r1);
	for(int i=1;i<=n;++i) a[i]=-a[i];
	build(l2,r2);
	for(int i=1;i<=n;++i) {
		put(R2,i+1,r2[i],i);
		put(R1,i+1,r1[i],i);
	}
	for(int i=n;i>=1;--i) {
		put(L2,l2[i],i-1,i);
		put(L1,l1[i],i-1,i);
	}
	h=t=0;
	vis[1]=1; qs[t++]=1; d[1]=0;
	while(h^t) {
		int x=qs[h++];
//		cerr<<x<<" "<<h<<","<<t<<"\n";
		aug(x);
	}
//	cerr<<"EZ.\n";
	printf("%d\n",d[n]);
	for(int i=1;i<=n;++i) {
		int o=i+M;
		while(o) L1[o].clear(),R1[o].clear(),
		L2[o].clear(),R2[o].clear(),o>>=1;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}