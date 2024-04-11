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
#define SZ 233333
char s[2333],t[2333]; int n,fm[SZ],tg[SZ],tt[SZ];
map<char,vector<int> > ms; vector<int> op;
void shift(int x)
{
	if(!x) return;
	op.pb(x); vector<int> cur;
	for(int i=n-1;i>=n-x;--i) cur.pb(fm[i]);
	for(int i=0;i<n-x;++i) cur.pb(fm[i]);
	for(int i=0;i<n;++i) fm[i]=cur[i]; 
}
int main()
{
	cin>>n>>s>>t;
	map<int,int> cnt;
	for(int i=0;t[i];++i) ++cnt[t[i]];
	for(int i=0;s[i];++i) --cnt[s[i]];
	for(auto p:cnt) if(p.se)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;s[i];++i) ms[s[i]].pb(i);
	for(int i=0;i<n;++i) fm[i]=i;
	for(int i=0;t[i];++i)
	{
		vector<int>&v=ms[t[i]];
		tt[i]=tg[i]=v.back(); v.pop_back();
	}
	for(int i=1;i<n;++i)
		reverse(tt+i,tt+n);
	for(int i=n-1;i>=0;--i)
	{
		int x=tt[i],p;
		for(int j=0;j<n;++j)
			if(fm[j]==x) p=j;
		shift(n-p-1); shift(1); shift(i);
	}
	printf("%d\n",int(op.size()));
	for(auto o:op) printf("%d ",o);puts("");
}