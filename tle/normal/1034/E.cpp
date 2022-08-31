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
#define SZ 2100000
typedef unsigned long long ull;
int n; ull a[SZ],b[SZ];
void fwt(ull*a)
{
	for(int j=0;j<n;++j)
		for(int i=0;i<(1<<n);++i)
			if(i&(1<<j))
				a[i]+=a[i^(1<<j)];
}
void ifwt(ull*a)
{
	for(int j=0;j<n;++j)
		for(int i=0;i<(1<<n);++i)
			if(i&(1<<j))
				a[i]-=a[i^(1<<j)];
}
char s[SZ];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<(1<<n);++i)
		a[i]=s[i]-48,
		a[i]<<=__builtin_popcount(i)*2;
	scanf("%s",s);
	for(int i=0;i<(1<<n);++i)
		b[i]=s[i]-48,
		b[i]<<=__builtin_popcount(i)*2;
	fwt(a); fwt(b);
	for(int i=0;i<(1<<n);++i)
		a[i]*=b[i];
	ifwt(a);
	for(int i=0;i<(1<<n);++i)
		printf("%llu",(a[i]>>(__builtin_popcount(i)*2))&3); 
}