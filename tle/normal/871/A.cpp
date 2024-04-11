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
#define SZ 6666
int rs[SZ],rn=0,mx[SZ];
int main()
{
	for(int i=2;i<SZ;++i)
	{
		int g=0;
		for(int j=2;j*j<=i&&!g;++j)
			if(i%j==0) g=1;
		if(g) rs[++rn]=i;
	}
	memset(mx,-127/3,sizeof mx);
	mx[0]=0;
	for(int i=1;i<SZ;++i)
		for(int j=1;j<=rn&&rs[j]<=i;++j)
			mx[i]=max(mx[i],mx[i-rs[j]]+1);
	int x,T; scanf("%d",&T);
	while(T--)
	{
	scanf("%d",&x);
	if(x<=12)
	{
		if(mx[x]>=0) printf("%d\n",mx[x]);
		else puts("-1");
	}
	else printf("%d\n",x/4-x%2);
	}
}