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
ll dv(ll a,ll b)
{
	if(!b) return 1e10;
	return a/b;
}
int main()
{
	ll n,p;
	cin>>n>>p;
	for(ll g=1;g<=40;++g)
	{
		//2^?? + pg=n
		ll t=n-p*g;
		if(t<0) continue;
		ll low=__builtin_popcountll(t),hi=t;
		if(low<=g&&g<=hi)
		{
			printf("%lld\n",g);
			return 0;
		}
		//g>=popcount
		//g<=n-p*g
		//g*(p+1)<=n
		//g<low?
		//g<=hi
	}
	//n-p*g>=0
	//g<=n-p*g
	//(p+1)*g<=n
	//p<=n/(g+1)
	vector<ll> G={dv(n,p+1),dv(n,p)};
	vector<ll> H;
	for(auto R:G)
		for(int u=-3;u<=3;++u)
			H.pb(R-u);
	for(int i=1;i<=40;++i) H.pb(i);
	sort(H.begin(),H.end());
	for(auto g:H)
	{
		if(g<1||g>1e10) continue;
		ll t=n-p*g;
		if(t<0) continue;
		ll low=__builtin_popcountll(t),hi=t;
		if(low<=g&&g<=hi)
		{
			printf("%lld\n",g);
			return 0;
		}
	}
	puts("-1");
}