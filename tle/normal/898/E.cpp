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
int n,a[SZ];
bool sq(int x)
{
	int r=sqrt(x);
	for(int g=r-3;g<=r+3;++g)
		if(g*g==x) return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	vector<int> s,t;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(sq(a[i]))
			s.pb(1+(a[i]==0));
		else
		{
			int x=sqrt(a[i]),dd=2e9;
			for(int r=x-2;r<=x+2;++r)
				dd=min(dd,abs(r*r-a[i]));
			t.pb(dd);
		}
	}
	ll ans=0;
	if(s.size()<t.size()) swap(s,t);
	sort(s.begin(),s.end());
	int g=s.size()-n/2;
	for(int j=0;j<g;++j) ans+=s[j];
	printf("%lld\n",ans);
}