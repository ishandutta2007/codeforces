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
int n,s,m,k,a[SZ],l[SZ],r[SZ],u[SZ],L[SZ];
int f[1505][1505];
int chk(int w)
{
	for(int i=1;i<=n;++i)
		u[i]=u[i-1]+(a[i]<=w),L[i]=i;
	int N=u[n];
	memset(f,0,sizeof f);
	for(int i=1;i<=s;++i)
	{
		int L=u[l[i]]+1,R=u[r[i]];
		if(L<=R)
			for(int j=L;j<=R;++j)
				::L[j]=min(::L[j],L-1);
	}
	for(int i=1;i<=N;++i)
		for(int w=m;w>=1;--w)
			f[i][w]=max(f[i-1][w],f[L[i]][w-1]+i-L[i]);
	return f[N][m];
}
int main()
{
	scanf("%d%d%d%d",&n,&s,&m,&k);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=s;++i)
		scanf("%d%d",l+i,r+i),--l[i];
	int l=0,r=1.001e9;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(chk(m)>=k) r=m; else l=m+1;
	}
	if(l>1e9) l=-1;
	printf("%d\n",l);
}