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
int n,t;
char str[SZ];
int r4[SZ];
int tmd[SZ];
int main()
{
	scanf("%d%d%s",&n,&t,str);
	int inf=1000000000;
	r4[n]=inf;
	int pnt=0;
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]=='.') {pnt=i; break;}
	}
	for(int i=n-1;i>=pnt+1;i--)
	{
		if(str[i]>='5') r4[i]=0;
		else if(str[i]=='4') r4[i]=r4[i+1]+1;
		else r4[i]=inf;
	}
	int p=n,ok=0;
	str[n]='0';
	for(int i=pnt+1;i<=n-1;i++)
	{
		if(str[i]<='3') continue;
		if(str[i]>='5') {p=i; ok=1; break;}
		if(str[i]=='4'&&r4[i]+1<=t) {p=i; ok=1; break;}
	}
	--p;
	int cc=0,bk=0;
	for(int i=p;i>=0;i--)
	{
		if(str[i]=='.')
		{
			bk=cc;
			continue;
		}
		tmd[cc++]=str[i]-'0';
	}
	if(ok) ++tmd[0];
	for(int i=0;i<cc;i++)
	{
		tmd[i+1]+=tmd[i]/10;
		tmd[i]%=10;
	}
	if(tmd[cc]) ++cc;
	int st=0;
	while(st<bk&&!tmd[st]) ++st;
	for(int i=cc-1;i>=st;i--)
	{
		putchar(tmd[i]+48);
		if(i==bk&&i!=st) putchar('.');
	}
}