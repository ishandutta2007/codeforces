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
typedef long double ld;
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
int n,sz[233]; Edg
ld C[233][233],t[55][55],g[55],h[55];
void dfs(int x,int f=0)
{
	memset(t[x],0,sizeof t[x]);
	t[x][0]=1; sz[x]=1; int s=0;
	for esb(x,e,b) if(b!=f)
	{
		dfs(b,x);
		for(int i=0;i<=sz[b];++i)
		{
			g[i]=0;
			for(int j=1;j<=sz[b];++j)
				if(j<=i)
					g[i]+=t[b][i-1]*2;
				else
					g[i]+=t[b][j-1];
		}
		for(int i=0;i<=sz[b]+s;++i) h[i]=0;
		for(int i=0;i<=sz[b];++i)
			for(int j=0;j<=s;++j)
				h[i+j]+=g[i]*t[x][j]
				*C[i+j][i]*C[s+sz[b]-i-j][sz[b]-i];
		s+=sz[b]; sz[x]+=sz[b];
		for(int i=0;i<=s;++i)
			t[x][i]=h[i];
	}
}
int main()
{
	for(int i=0;i<233;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	for(int i=1;i<=n;++i)
	{
		dfs(i); ld u=t[i][0];
		for(int j=1;j<=n-1;++j) u/=j*2;
		printf("%.10lf\n",double(u));
	}
}