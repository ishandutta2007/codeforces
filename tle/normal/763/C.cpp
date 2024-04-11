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
int n,m,g,a[SZ],x[SZ],y[SZ],z[SZ],t[SZ];
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
map<int,int> cnt;
int ran_() {return int(rand()/double(RAND_MAX)*2333333)%32768;}
int ran() {return ran_()*32768+ran_();}
int qwq(int *x,int n,int m,int times=0)
{
	if(times>50) return -1;
	if(m<=50)
	{
		cnt.clear();
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(i!=j)
				{
					int d=(x[i]-x[j]+n)%n;
					if(gcd(d,n)==1&&++cnt[d]==m-1)
						return d;
				}
		return -1;
	}
	if(m==n-1) return 1;
	int w=x[ran()%m+1],an=0,bn=0,cn=0;
	if(w+w<n) for(int i=1;i<=m;i++)
	{
		int r=w+w-x[i];
		if(r<0) y[++an]=r+n; else z[++bn]=r;
	}
	else for(int i=1;i<=m;i++)
	{
		int r=w+w-x[i];
		if(r<n) y[++an]=r; else z[++bn]=r-n;
	}
	for(int i=1,j=an,k=bn;i<=m;i++)
	{
		while(j&&y[j]<x[i]) j--;
		while(k&&z[k]<x[i]) k--;
		if((!j||x[i]!=y[j])&&(!k||x[i]!=z[k]))
			t[++cn]=x[i];
	}
	if(cn>1)
	{
		for(int i=0;i<=cn;i++)
			x[i]=t[i];
		return qwq(x,n,cn,times+1);
	}
	return qwq(x,n,m,times+1);
}
int main()
{
	scanf("%d%d",&n,&m); g=x[0]=n;
	for(int i=1;i<=m;i++) scanf("%d",x+i);
	sort(x+1,x+1+m);
	for(int i=1;i<=m;i++) g=gcd(g,x[i]-x[1]);
	if(m==1){printf("%d 1\n",x[1]); return 0;}
	if(m==n/g)
	{printf("%d %d\n",x[1],g); return 0;}
	for(int i=1;i<=m;i++) a[i]=x[i]/g;
	int d=qwq(a,n/g,m);
	if(d==-1) return puts("-1"),0;
	d*=g; int s=x[1],cf=0;
	for(int i=1;i<=m;i++)
		if(!binary_search(x+1,x+m+1,(x[i]+d)%n))
			cf++, s=x[i];
	if(cf<=1) printf("%d %d\n",s,(n-d)%n);
	else puts("-1");
	return 0;
}