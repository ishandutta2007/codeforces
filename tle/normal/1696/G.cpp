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
int n,q,x,y,b[SZ];
struct g {
bool ne;
ld v[3][3];
ld gg() {
	ld x=0;
	for(int i=0;i<3;++i)
	for(int j=0;j<3;++j) x=max(x,v[i][j]);
	return x;
}
ld f() {
	return gg();
	/*
	ll t=gg();
	ll o=s-t;
	if(x>y) swap(x,y); 
	ld ans=t*1./y;
	ans=max(ans,s*1./(x+y));
	return ans;*/
}
}e;
const int M=262144;
g seg[SZ];
g sing(ll v) {
	g x; x.ne=1;
	memset(&x.v,0,sizeof x.v);
	x.v[1][1]=v*1./y;
	x.v[2][2]=v*1./(::x+y);
	return x;
}
g operator + (g a,g b) {
	if(!a.ne) return b;
	if(!b.ne) return a;
	g c; c.ne=1;// c.s=a.s+b.s;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j) {
			c.v[i][j]=0;
			for(int k=0;k<3;++k)
				for(int l=0;l<3;++l) if((!!k)+(!!l)<=1||(k==2&&l==2))
					c.v[i][j]=max(c.v[i][j],a.v[i][k]+b.v[l][j]);
		}
	return c;
}
int main() {
	scanf("%d%d",&n,&q);
	scanf("%d%d",&x,&y);
	if(x>y) swap(x,y); 
	for(int i=1;i<=n;++i) {
		scanf("%d",b+i);
		seg[i+M]=sing(b[i]);
	}
	for(int i=M-1;i>=1;--i)
		seg[i]=seg[i+i]+seg[i+i+1];
	while(q--) {
		int o,a,b;
		scanf("%d%d%d",&o,&a,&b);
		if(o==1) {
			seg[a+=M]=sing(b);
			while(a>>=1)
				seg[a]=seg[a+a]+seg[a+a+1];
		}
		else {
			int l=a+M-1,r=b+M+1;
			g L=e,R=e;
			for(;l^r^1;l>>=1,r>>=1) {
				if(~l&1) L=L+seg[l^1];
				if(r&1) R=seg[r^1]+R;
			}
			L=L+R;
			printf("%.10lf\n",L.f());
		}
	}
}