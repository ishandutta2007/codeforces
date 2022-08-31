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
int n; ll l[SZ],su[SZ],hz[SZ],ans=0;
char s[SZ];
void go(char c,ll uu)
{
	for(int i=1;i<=n;++i)
		if(s[i]=='L') su[i]=su[i-1]-l[i];
		else su[i]=su[i-1]+l[i];
	hz[n+1]=8e18;
	for(int i=n;i>=1;--i)
		hz[i]=min(hz[i+1],su[i]);
	ll fr=0;
	for(int i=1;i<=n;++i)
		if(s[i]==c)
		{
			ll u=min(hz[i]-fr,l[i]*2);
			l[i]-=u; fr+=u; ans-=u*uu;
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",l+i);
	scanf("%s",s+1);
	int sb=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='W')
		{
			if(s[sb]=='G'||sb==0) sb=i;
		}
		else if(s[i]=='G')
		{
			if(!sb) sb=i;
		}
		if(s[i]=='L')
		{
			su[i]=su[i-1]-l[i];
			if(su[i]<0)
				l[sb]-=su[i], su[i]=0;
		}
		else su[i]=su[i-1]+l[i];
	}
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='W') ans+=3*l[i];
		else if(s[i]=='G') ans+=5*l[i];
		else ans+=l[i];
	}
	go('G',2); go('W',1);
	printf("%lld\n",ans);
}