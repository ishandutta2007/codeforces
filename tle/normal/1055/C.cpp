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
ll cons(ll g,ll l,ll r,ll t1,ll t2)
{
	set<ll> u;
	for(int p=-2;p<=2;++p)
		u.insert((t1-r)/g+p),
		u.insert((t2-r)/g+p);
	for(int p=-2;p<=2;++p)
		u.insert((t1-l)/g+p),
		u.insert((t2-l)/g+p);
	ll ans=0;
	for(auto s:u)
	{
		ll L=max(t1,s*g+l),
		R=min(t2,s*g+r);
		ans=max(ans,R-L+1);
	}
	return ans;
}
int main()
{
	ll la,ra,ta,lb,rb,tb;
	cin>>la>>ra>>ta>>lb>>rb>>tb;
	ll g=__gcd(ta,tb);
	//[g*k+l,g*k+r] [lb,rb]
	printf("%lld\n",max(cons(g,la,ra,lb,rb),
	cons(g,la,ra,lb+tb,rb+tb)));
}