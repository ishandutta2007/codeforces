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
const int M=262144;
int seg[SZ],*a=seg+M;
int qor(int l,int r)
{
	int ans=0;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ans|=seg[l^1];
		if(r&1) ans|=seg[r^1];
	}
	return ans;
}
map<int,int> pv;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=M-1;i>=1;--i)
		seg[i]=seg[i+i]|seg[i+i+1];
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		int&ps=pv[a[i]],p=ps+1; ps=i;
		int l=p,r=i;
		while(l<r)
		{
			int m=(l+r)>>1;
			if(qor(m,i)==a[i]) r=m;
			else l=m+1;
		}
		int L=l;
		l=i,r=n;
		while(l<r)
		{
			int m=(l+r+1)>>1;
			if(qor(i,m)==a[i]) l=m;
			else r=m-1;
		}
		int R=l;
		ans-=(i-L+1)*ll(R-i+1)-1;
		ans+=i-1;
	}
	printf("%lld\n",ans);
}