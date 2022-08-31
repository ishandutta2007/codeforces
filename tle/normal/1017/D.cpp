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
int n,q,m,u[6666],ww[23333],c[6666];
int r[6666][105];
int ts[6666];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=n-1;i>=0;--i) scanf("%d",ww+i);
	for(int i=0;i<(1<<n);++i)
	{
		for(int j=0;j<n;++j) if(i&(1<<j));
		else u[i]+=ww[j];
		u[i]=min(u[i],101);
	}
	for(int i=1;i<=m;++i)
	{
		static char tmp[23];
		scanf("%s",tmp);
		int w=0;
		for(int j=0;tmp[j];++j)
			w=w*2+tmp[j]-48;
		++c[w];
	}
	for(int i=0;i<(1<<n);++i)
	{
		for(int j=0;j<=101;++j) ts[j]=0;
		for(int j=0;j<(1<<n);++j)
			ts[u[i^j]]+=c[j];
		int su=0;
		for(int j=0;j<=100;++j)
			r[i][j]=(su+=ts[j]);
	}
	for(int i=1;i<=q;++i)
	{
		static char tmp[23]; int k;
		scanf("%s%d",tmp,&k);
		int w=0;
		for(int j=0;tmp[j];++j)
			w=w*2+tmp[j]-48;
		printf("%d\n",r[w][k]);
	}
}