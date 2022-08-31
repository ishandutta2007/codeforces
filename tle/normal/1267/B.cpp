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
vector<pii> cp;
char s[SZ];
int main()
{
	int ls=0,cnt=0;
	scanf("%s",s);
	for(int i=0;s[i];++i)
	{
		char c=s[i];
		if(c!=ls&&cnt)
			cp.pb(pii(ls,cnt));
		if(c!=ls) cnt=0,ls=c;
		++cnt;
	}
	if(cnt) cp.pb(pii(ls,cnt));
	auto ww=cp;
	reverse(ww.begin(),ww.end());
	bool ok=1;
	for(int i=0;i<cp.size();++i)
		ok&=ww[i].fi==cp[i].fi;
	if((!ok)||(cp.size()%2==0))
	{
		puts("0");
		return 0;
	}
	int u=cp.size()/2;
	if(cp[u].se+1<3)
	{
		puts("0");
		return 0;
	}
	for(int j=0;j<u;++j)
		if(cp[j].se+ww[j].se<3)
		{
			puts("0");
			return 0;
		}
	printf("%d\n",cp[u].se+1);
}