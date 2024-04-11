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
#define SZ
int main()
{
	ll p,k;
	cin>>p>>k;
	int g=-1; ll p_=p;
	vector<ll> rs,op;
	while(1)
	{
		if(g==-1) p/=k;
		else p=(p+k-1)/k;
		if(!p) break;
		rs.pb(p*g);
		g*=-1;
	}
	op.pb(0);
	for(auto a:rs) op.pb(a);
	for(unsigned _=0;_<rs.size();++_)
		op[_]+=rs[_]*k;
	op[0]+=p_;
	while(op.size()&&!op.back()) op.pop_back();
	printf("%d\n",int(op.size()));
	for(auto a:op) printf("%d ",a);
}