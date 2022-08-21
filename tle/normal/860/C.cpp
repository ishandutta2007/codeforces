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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n; set<string> ex[2];
vector<string> dm[2],tg[2];
set<string> gs;
string gen()
{
	while(1)
	{
		string s;
		for(int i=1;i<=6;++i)
		{
			if(rand()&1) s.pb(rand()%10+48);
			else s.pb(rand()%26+'a');
		}
		if(gs.count(s)) continue;
		return s;
	}
}
vector<pair<string,string> > vec;
void mov(string a,string b)
{
	vec.pb(make_pair(a,b));
}
int main()
{
	scanf("%d",&n); int e=0;
	for(int i=1;i<=n;++i)
	{
		char tmp[15]; int g;
		scanf("%s%d",tmp,&g);
		gs.insert(tmp);
		g=!g; if(!g) ++e;
		ex[g].insert(tmp);
	}
	for(int i=1;i<=e;++i)
	{
		char buf[15];
		sprintf(buf,"%d",i);
		string g=buf;
		if(ex[0].count(g)) ex[0].erase(g);
		else if(ex[1].count(g))
			ex[1].erase(g),dm[1].pb(g);
		else tg[0].pb(g);
	}
	for(int i=e+1;i<=n;++i)
	{
		char buf[15];
		sprintf(buf,"%d",i);
		string g=buf;
		if(ex[1].count(g)) ex[1].erase(g);
		else if(ex[0].count(g))
			ex[0].erase(g),dm[0].pb(g);
		else tg[1].pb(g);
	}
	string extra=gen();
	if(!tg[0].size()&&!tg[1].size())
	{
		if(dm[0].size()) tg[0].pb(extra);
		else if(dm[1].size()) tg[1].pb(extra);
	}
	while(dm[0].size()||dm[1].size())
	{
		if(tg[0].size()&&dm[0].size())
		{
			string g=dm[0].back();
			dm[0].pop_back();
			mov(g,tg[0].back());
			tg[0].pop_back();
			tg[1].pb(g);
		}
		else if(tg[1].size()&&dm[1].size())
		{
			string g=dm[1].back();
			dm[1].pop_back();
			mov(g,tg[1].back());
			tg[1].pop_back();
			tg[0].pb(g);
		}
		else throw "GG";
	}
	for(auto s:ex[0])
	{
		mov(s,tg[0].back()); tg[0].pop_back();
	}
	for(auto s:ex[1])
	{
		mov(s,tg[1].back()); tg[1].pop_back();
	}
	if(tg[0].size()) mov(extra,tg[0].back());
	if(tg[1].size()) mov(extra,tg[1].back());
	printf("%d\n",int(vec.size()));
	for(auto g:vec) printf("move %s %s\n",g.fi.c_str(),g.se.c_str());
}