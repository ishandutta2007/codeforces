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
int n,q,a[SZ],L[SZ],R[SZ],g[SZ],ff[SZ];
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;++i)
		L[i]=n+1,R[i]=0;
	L[1]=1; R[1]=n;
	int z=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i),
		L[a[i]]=min(L[a[i]],i),
		R[a[i]]=max(R[a[i]],i);
		if(!a[i]) z=i;
	}
	for(int i=q;i>=1;--i)
	{
		if(L[i]>R[i])
		{
			if(z) L[i]=R[i]=z;
			else {puts("NO"); return 0;}
		}
		else z=L[i];
	}
	for(int i=q;i>=1;--i)
		for(int j=gf(L[i]);j<=R[i];)
			g[j]=i,ff[j]=j+1,j=gf(j);
	for(int i=1;i<=n;++i)
		if(a[i]&&g[i]!=a[i]) {puts("NO"); return 0;}
	puts("YES");
	for(int i=1;i<=n;++i)
		printf("%d ",g[i]);
}