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
#define SZ 666666
int n,m,l,a[SZ],ans=0;
int main()
{
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i]>l) ++ans;
		if(a[i]>l&&a[i-1]>l) --ans;
	}
	for(int i=1;i<=m;++i)
	{
		int o;
		scanf("%d",&o);
		if(o==0)
		{
			printf("%d\n",ans);
			continue;
		}
		int p,q;
		scanf("%d%d",&p,&q);
		if(a[p]>l) continue;
		a[p]+=q;
		if(a[p]>l)
		{
			++ans;
			if(a[p-1]>l) --ans;
			if(a[p+1]>l) --ans;
		}
	}
}