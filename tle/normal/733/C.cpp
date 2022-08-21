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
int n,a[SZ],k,b[SZ],qzh[SZ];
pii qs[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i), qzh[i]=qzh[i-1]+a[i];
	scanf("%d",&k);
	for(int i=1;i<=k;i++) scanf("%d",b+i);
	int cur=0;
	for(int i=1;i<=k;i++)
	{
		int s=cur;
		while(s<=n&&qzh[s]-qzh[cur]<b[i]) ++s;
		//merge [cur,s]
		if(s>n||qzh[s]-qzh[cur]!=b[i])
		{
			puts("NO"); return 0;
		}
		qs[i]=pii(cur+1,s);
		cur=s;
	}
	if(cur!=n)
	{
		puts("NO"); return 0;
	}
	for(int i=k;i>=1;i--)
	{
		int maxn=0;
		int R=qs[i].se,L=qs[i].fi;
		if(L==R) continue;
		//find a safe maximum
		for(int j=L;j<=R;j++)
		maxn=max(maxn,a[j]);
		int safe=-1;
		for(int j=L;j<=R;j++)
		{
			if(a[j]!=maxn) continue;
			if(j!=L&&a[j-1]!=maxn) {safe=j; break;}
			if(j!=R&&a[j+1]!=maxn) {safe=j; break;}
		}
		if(safe==-1)
		{
			puts("NO"); return 0;
		}
	}
	puts("YES");
	for(int i=k;i>=1;i--)
	{
		int maxn=0;
		int R=qs[i].se,L=qs[i].fi;
		if(L==R) continue;
		//find a safe maximum
		for(int j=L;j<=R;j++)
		maxn=max(maxn,a[j]);
		int safe=-1,p=0;
		for(int j=L;j<=R;j++)
		{
			if(a[j]!=maxn) continue;
			if(j!=L&&a[j-1]!=maxn) {safe=j; p=0; break;}
			if(j!=R&&a[j+1]!=maxn) {safe=j; p=1; break;}
		}
		if(p)
		{
			a[safe]+=a[safe+1]; printf("%d R\n",safe);
			for(int i=safe+1;i<R;i++) a[i]=a[i+1]; --R;
		}
		else
		{
			a[safe-1]+=a[safe]; printf("%d L\n",safe);
			for(int i=safe+1;i<=R;i++) a[i-1]=a[i]; --R; --safe;
		}
		for(int i=safe;i<R;i++) printf("%d R\n",safe);
		for(int i=safe;i>L;i--) printf("%d L\n",i);
	}
}