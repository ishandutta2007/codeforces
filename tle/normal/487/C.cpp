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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
ll qp(ll a,ll b,ll MOD)
{
	a%=MOD; ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return ans;
}
ll m2[SZ];
void p2(int x)
{
	if(x==4)
	{
		puts("YES\n1\n3\n2\n4");
		return;
	}
	bool np=0;
	for(int i=2;i<x;i++)
	{
		if(x%i==0) np=1;
	}
	if(np)
	{
		puts("NO");
		return;
	}
	m2[1]=1;
	for(int i=2;i<x;i++)
		m2[i]=i*qp(i-1,x-2,x)%x;
	m2[x]=x;
	puts("YES");
	for(int i=1;i<=x;i++)
		printf("%lld\n",m2[i]);
	return;
}
//pattern: 1,0,2,7,3,6,4,5
ll qzh[SZ],a[SZ];
void p1(int x)
{
	if(x==1)
	{
		puts("1");
		return;
	}
	if(x%2==1)
	{
		puts("0");
		return; 
	}
	int cnt=-1;
	for(int i=1;i<=x;i+=2)
		qzh[i]=++cnt;
	qzh[x]=++cnt;
	for(int i=x-2;i>=1;i-=2)
		qzh[i]=++cnt;
	printf("2");
	for(int i=1;i<=x;i++)
	{
		int s=int((qzh[i]-qzh[i-1])%x+x)%x;
		if(s==0) s=x;
		printf(" %d",s);
	}
	puts("");
}
int main()
{
	int n;
	cin>>n;
	p2(n);
}