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
int a,b,c;
int main()
{
	scanf("%d\n%d:%d",&a,&b,&c);
	char sb[5],sc[5];
	sprintf(sb,"%02d",b);
	sprintf(sc,"%02d",c);
	pii aa=pii(233,0),bb=pii(233,0);
	for(int i=(a==12);i<a+(a==12);i++)
	{
		char s[5]; int c=0;
		sprintf(s,"%02d",i);
		for(int j=0;j<2;j++) c+=(s[j]!=sb[j]);
		aa=min(aa,pii(c,i));
	}
	for(int i=0;i<60;i++)
	{
		char s[3]; int c=0;
		sprintf(s,"%02d",i);
		for(int j=0;j<2;j++) c+=(s[j]!=sc[j]);
		bb=min(bb,pii(c,i));
	}
	printf("%02d:%02d\n",aa.se,bb.se);
}