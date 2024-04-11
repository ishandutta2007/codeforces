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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#ifdef LOCAL
#define TIMER cerr<<clock()<<"ms\n"
#else
#define TIMER
#endif
#define SZ 666666
int n,x;
double p[233333];
struct matrix {int n; double s[133][133];};
matrix operator * (matrix a,matrix b)
{
	matrix ans; ans.n=a.n;
	for(int i=0;i<a.n;i++)
	{
		for(int j=0;j<a.n;j++)
		{
			ld rp=0;
			for(int k=0;k<a.n;k++) rp=rp+a.s[i][k]*b.s[k][j];
			ans.s[i][j]=rp;
		}
	}
	return ans;
}
matrix I(int n)
{
	matrix ans; ans.n=n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) ans.s[i][j]=i==j;
	}
	return ans;
}
matrix quickpow(matrix a,ll b)
{
	matrix ans=I(a.n);
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a; b>>=1;
	}
	return ans;
}
matrix t;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=0;i<=x;i++) scanf("%lf",p+i);
	int tt=1;
	while(tt<=x) tt<<=1;
	//cout<<"hehe\n";
	t.n=x=tt;
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<x;j++) t.s[i][j]=p[i^j];
	}
	matrix r=quickpow(t,n);
	printf("%.10lf\n",1-r.s[0][0]);
}