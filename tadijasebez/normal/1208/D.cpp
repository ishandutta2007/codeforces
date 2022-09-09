#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>
#include <deque>
#include <complex>
#include <tuple>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb double
#define mt make_tuple
void ckmn(int &a, int b){ a=min(a,b);}
void ckmn(ll &a, ll b){ a=min(a,b);}
void ckmx(int &a, int b){ a=max(a,b);}
void ckmx(ll &a, ll b){ a=max(a,b);}
int mod;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return pow(x,mod-2);}
const int N=200050;
ll a[N];
int id[N],p[N];
struct BIT
{
	ll sum[N];
	BIT(){}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	ll Get(int i){ ll ans=0;for(;i;i-=i&-i) ans+=sum[i];return ans;}
} ST;
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) ST.Set(i,i);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),id[i]=i;
	for(int i=n;i>=1;i--)
	{
		int top=n,bot=1,mid,ans;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(ST.Get(mid)>a[i]) ans=mid,top=mid-1;
			else bot=mid+1;
		}
		p[i]=ans;
		ST.Set(p[i],-p[i]);
	}
	for(int i=1;i<=n;i++) printf("%i ",p[i]);
	return 0;
}