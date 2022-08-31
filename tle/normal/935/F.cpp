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
const int M=131072;
#define SZ 666666
ll mx[4][M+M+3];
int n,vl[4],vm[4],vr[4],vx[4]; ll a[SZ],ans=0,bs[SZ];
void edt(int x,int y)
{
	for(;x<=n;x+=x&-x) bs[x]+=y;
}
ll su(int x)
{
	ll s=0;
	for(;x>=1;x-=x&-x) s+=bs[x];
	return s;
}
void reb(int i)
{
	ll L=su(i-1),MM=su(i),R=su(i+1);
	ll e=abs(L-MM)+abs(MM-R);
	for(int j=0;j<4;++j)
	{
		mx[j][i+M]=vl[j]*L+vm[j]*MM+vr[j]*R-e;
		for(int g=(i+M)>>1;g;g>>=1)
			mx[j][g]=max(mx[j][g+g],mx[j][g+g+1]);
	}
}
int main()
{
	for(int i=0;i<4;++i)
	{
		int sa=(i&1)?1:(-1),sb=(i&2)?1:(-1);
		//sa*(b+x-a)+sb*(b+x-c)
		vl[i]=-sa; vm[i]=sa+sb; vr[i]=-sb; vx[i]=sa+sb;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i),edt(i,a[i]-a[i-1]);
	for(int i=1;i<n;++i)
		ans+=abs(a[i]-a[i+1]);
	memset(mx,-127/3,sizeof mx);
	for(int i=2;i<n;++i)
	{
		ll e=abs(a[i]-a[i-1])+abs(a[i]-a[i+1]);
		for(int j=0;j<4;++j)
			mx[j][i+M]=vl[j]*a[i-1]+vm[j]*a[i]+vr[j]*a[i+1]-e;
	}
	for(int i=0;i<4;++i)
		for(int j=M-1;j>=1;--j)
			mx[i][j]=max(mx[i][j+j],mx[i][j+j+1]);
	int q; scanf("%d",&q);
	while(q--)
	{
		int o,l,r,x;
		scanf("%d%d%d%d",&o,&l,&r,&x);
		if(o==2)
		{
			ans-=abs(su(l)-su(l-1))+abs(su(r)-su(r+1));
			edt(l,x); edt(r+1,-x);
			for(int j=l-1;j<=l+1;++j) reb(j);
			for(int j=r-1;j<=r+1;++j) reb(j);
			ans+=abs(su(l)-su(l-1))+abs(su(r)-su(r+1));
			continue;
		}
		ll dt=-1e18;
		for(int j=0;j<4;++j)
		{
			ll aa=-1e18;
			for(int a=l+M-1,b=r+M+1;a^b^1;a>>=1,b>>=1)
			{
				if(~a&1) aa=max(aa,mx[j][a^1]);
				if(b&1) aa=max(aa,mx[j][b^1]);
			}
			dt=max(dt,aa+vx[j]*(ll)x); 
		}
		printf("%lld\n",dt+ans);
	}
}