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
int n,m,a; ll d,t[233333],cd=1;
int main()
{
	scanf("%d%d%d%lld",&n,&m,&a,&d);
	for(int i=1;i<=m;++i)
		scanf("%lld",t+i);
	ll pl=d/a+1,ans=0;
	for(int i=1;i<=m;)
	{
		if(t[i]>=d)
		{
			ll ra=(t[i]-d)/a-2;
			if(ra>n) ra=n;
			if(cd<=ra)
			{
				ll stp=(ra-cd)/pl;
				cd+=stp*pl; ans+=stp;
			}
		}
		//(t[i]-d)>(ll)a*cd
		while(t[i]>(ll)a*cd+d&&cd<=n) cd+=pl,++ans;
		if(cd>n||(ll)a*cd>t[i])
		{
			++ans; ll R=t[i]+d;
			while(t[i]<=R&&i<=m) ++i;
			cd=max(cd,R/a+1);
		}
		else
		{
			++ans; ll R=(ll)a*cd+d;
			while(t[i]<=R&&i<=m) ++i;
			cd=max(cd,R/a+1);
		}
	}
	if(cd<=n)
	{
		ll stp=(n-cd)/pl;
		cd+=stp*pl; ans+=stp;
	}
	while(cd<=n) cd+=pl,++ans;
	printf("%lld\n",ans);
}