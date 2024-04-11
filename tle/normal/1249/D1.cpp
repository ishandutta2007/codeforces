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
int n,k,l[SZ],r[SZ];
map<int,vector<pii>> ev;
multiset<pii> g;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>l[i]>>r[i];
		ev[l[i]].pb(pii(r[i],i));
	}
	vector<int> er;
	for(auto t:ev)
	{
		while(g.size()&&g.begin()->fi<t.fi)
			g.erase(g.begin());
		for(auto w:t.se)
			g.insert(w);
		while(g.size()>k)
			er.pb((--g.end())->se),
			g.erase(--g.end());
	}
	cout<<er.size()<<"\n";
	for(auto e:er)
		cout<<e<<' ';
}