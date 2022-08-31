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
#define SZ 66666
int n,qa[SZ],qb[SZ];
int qry_(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int xx; scanf("%d",&xx);
	return xx;
}
int qry(int x,int y)
{return qa[x]^qa[0]^qb[y];}
int p[SZ],b[SZ],pp[SZ];
bool vv[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) qa[i]=qry_(i,0);
	for(int i=0;i<n;++i) qb[i]=qry_(0,i);
	int ans=0;
	for(int i=0;i<n;++i)
	{
		bool gg=0;
		for(int j=0;j<n;++j) p[j]=qry(j,i);
		for(int j=0;j<n;++j) vv[j]=0;
		for(int j=0;j<n;++j) gg|=vv[p[j]],vv[p[j]]=1;
		for(int j=0;j<n;++j) b[p[j]]=j;
		for(int j=0;j<n;++j)
			if(qa[j]!=(p[j]^b[0])) gg=1;
		for(int j=0;j<n;++j)
			if(qb[j]!=(b[j]^p[0])) gg=1;
		if(gg) continue;
		++ans;
		for(int j=0;j<n;++j) pp[j]=p[j];
	}
	puts("!");
	printf("%d\n",ans);
	for(int j=0;j<n;++j) printf("%d ",pp[j]);
	fflush(stdout);
}