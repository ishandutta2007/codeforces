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
#include <unordered_set>
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
#define SZ 2000555
int t,n,c[SZ],d[SZ];
int is[SZ],in=0;
void sol()
{
	in=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) d[i]=0;
	for(int i=1;i<=n;++i)
		scanf("%d",c+i),++d[c[i]];
	int R=2e9;
	for(int i=1;i<=n;++i) if(d[i])
		R=min(R,d[i]+1),is[++in]=i;
	//d[i]
	int X=n;
	for(int x=2;x<=R;++x)
	{
		bool ok=1;
		int ne=0;
		for(int p=1;p<=in;++p)
		{
			int j=is[p];
			//1) d[j]%x==0
			//2) [d[j]/x]+1<=x-d[j]+[d[j]/x]*x
			//   [d[j]/x]*(1-x)+d[j]<=x-1
			//   x larger -> harder
			//(d[j]+x-1)/x<=-d[j]%x
			
			//(x-1)*k+x*u=D
			//x*(k+u)-k=D
			//(D+k)/x=k+u
			//S*x-D<=S
			int L=(d[j]+x-1)/x;//,R=d[j]/(x-1);
			ne+=L;
			if((x-d[j]%x)%x>L)
			{
				ok=0;
				break;
			}
		}
		if(ok) X=min(X,ne);
	}
	printf("%d\n",X);
}
int main()
{
	scanf("%d",&t);
	while(t--) sol();
}