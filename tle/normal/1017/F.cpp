#pragma GCC optimize("-O3","-funroll-all-loops")
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
#define S 100000000
typedef unsigned us;
us np[S/32+5];
#define U 200000
bitset<U> nps;
int n,sp[23333],sn,pnn; us A,B,C,D,ans;
inline void deal(us p)
{
	us F=((A*p+B)*p+C)*p+D,g=n;
	while(g/=p) ans+=F*g;
}
int main()
{
	scanf("%d%u%u%u%u",&n,&A,&B,&C,&D);
	int w=sqrt(n); w+=3;
	if(w>n) w=n; nps[1]=1;
	for(int i=2;i<=w;++i) if(!nps[i])
	{
		deal(i); sp[++sn]=i;
		for(int j=i+i;j<=w;j+=i) nps[j]=1;
	}
	for(int p=w+1;p<=n;)
	{
		memset(&np,0,sizeof np);
		int r=min(p+S-3,n),rp=r-p;
		for(int j=1;j<=sn;++j)
		{
			int t=sp[j],x=t;
			x+=(p-t)/t*t;
			while(x<p) x+=t; x-=p;
			while(x<=rp) np[x>>5]|=1u<<(x&31),x+=t; 
		}
		for(int j=0;j<=rp;++j)
			if((np[j>>5])&(1u<<(j&31)));else deal(j+p);
		p=r+1;
	}
	printf("%u\n",ans);
}