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
Edgc
map<int,int> vis;
int n,s,a[SZ],b[SZ],id,vv[SZ],ed;
vector<int> cur,vs[SZ]; int vn;
void dfs(int x)
{
	for(int&e=fst[x];e;e=nxt[e]) if(!vv[vc[e]])
	{
		int c=vc[e]; vv[vc[e]]=1;
		dfs(vb[e]); cur.pb(c);
	}
}
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),vis[a[i]]=1;
	for(auto&t:vis) t.se=++id;
	for(int i=1;i<=n;++i)
		b[i]=a[i]=vis[a[i]];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;++i) if(a[i]!=b[i])
		++ed,ad_de(a[i],b[i],i);
	if(ed>s)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=id;++i)
		if(fst[i])
		{
			dfs(i);
			vs[++vn]=cur;
			cur.clear();
		}
	int tj=min(vn,s-ed);
	if(tj<=2) tj=0;
	vector<int> ta,tb;
	for(int i=1;i<=tj;++i)
	{
		ta.insert(ta.end(),vs[vn].begin(),vs[vn].end());
		tb.pb(vs[vn--].back());
	}
	if(tj)
	{
		reverse(tb.begin(),tb.end());
		vs[++vn]=tb; vs[++vn]=ta;
	}
	printf("%d\n",vn);
	for(int i=1;i<=vn;++i)
	{
		printf("%d\n",int(vs[i].size()));
		for(auto g:vs[i]) printf("%d ",g);
		puts("");
	}
}