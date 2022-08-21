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
int n,m,a[23333];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	int s=n>>1,t=n-s;
	set<int> A,B;
	for(int i=0;i<(1<<s);++i)
	{
		ll r=0;
		for(int j=0;j<s;++j)
			if(i&(1<<j)) r+=a[j];
		A.insert(r%m);
	}
	for(int i=0;i<(1<<t);++i)
	{
		ll r=0;
		for(int j=0;j<t;++j)
			if(i&(1<<j)) r+=a[s+j];
		B.insert(r%m);
	}
	int ma=*--A.end(),ans=0;
	for(auto g:B)
	{
		ans=max(ans,(g+ma)%m);
		if(!g) continue;
		ans=max(ans,(g+*(--A.upper_bound(m-1-g)))%m);
	}
	printf("%d\n",ans);
}