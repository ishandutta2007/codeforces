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
int pr[SZ],n; pii p[SZ];
map<pii,int> cp;
vector<pii> A,B;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].fi,&p[i].se),
		cp[p[i]]=i,pr[p[i].se]=p[i].fi,
		pr[p[i].fi]=p[i].se;
	for(int i=1;i<=n;++i)
		if(p[i].fi<p[i].se) A.pb(p[i]);
		else B.pb(p[i]);
	vector<int> v1;
	vector<int> v2;
	{
	priority_queue<int> pq;
	for(auto t:A) pq.push(t.se);
	int w=n*2;
	while(!pq.empty())
	{
		auto t=pq.top(); pq.pop();
		int s=pr[t];
		if(s>w) continue;
		w=t; v1.pb(cp[pii(s,t)]);
	}
	}
	{
	priority_queue<int,vector<int>,greater<int>> pq;
	for(auto t:B) pq.push(t.se);
	int w=1;
	while(!pq.empty())
	{
		auto t=pq.top(); pq.pop();
		int s=pr[t];
		if(s<w) continue;
		w=t; v2.pb(cp[pii(s,t)]);
	}
	}
	if(v1.size()<v2.size()) swap(v1,v2);
	printf("%d\n",int(v1.size()));
	for(auto t:v1) printf("%d ",t);
}