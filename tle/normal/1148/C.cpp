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
#include <assert.h>
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
int n,p[SZ],pp[SZ],rp[SZ];
vector<pii> vs;
bool o(int a,int b)
{
	return abs(b-a)*2>=n;
}
void swp(int a,int b)
{
	if(a==b) return;
	assert(o(a,b));
	vs.pb(pii(a,b));
	swap(pp[a],pp[b]);
}
void my_swap(int a,int b)
{
	if(a>b) swap(a,b);
	if(o(a,b)) swp(a,b);
	else
	{
		for(auto x:{1,n})
		{
			if(o(a,x)&&o(b,x))
			{
				swp(b,x);
				swp(a,x);
				swp(b,x);
				return;
			}
		}
		swp(n,a); swp(b,1);
		swp(1,n);
		swp(n,a); swp(b,1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",p+i),
		rp[p[i]]=i,pp[i]=p[i];
	for(int i=1;i<=n;++i)
		if(p[i]!=i)
		{
			int t=rp[i];
			my_swap(t,i);
			swap(p[t],p[i]);
			rp[p[t]]=t;
			rp[p[i]]=i;
		}
	assert(is_sorted(pp+1,pp+1+n));
	printf("%d\n",int(vs.size()));
	for(auto x:vs)
		printf("%d %d\n",x.fi,x.se);
}