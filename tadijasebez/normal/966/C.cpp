#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
bool ckmax(int &a, int b){ a=max(a,b);return a==b;}
bool ckmin(int &a, int b){ a=min(a,b);return a==b;}
bool ckmax(ll &a, ll b){ a=max(a,b);return a==b;}
bool ckmin(ll &a, ll b){ a=min(a,b);return a==b;}
const int mod=1e9+7;
int pow(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
int inv(int x){ return pow(x,mod-2);}
void add(int &a, int b){ a+=b;if(a>=mod) a-=mod;}
void sub(int &a, int b){ a-=b;if(a<0) a+=mod;}
void mul(int &a, int b){ a=(ll)a*b%mod;}
void div(int &a, int b){ mul(a,inv(b));}
const int L=62;
const int M=100050*L*2;
int root[L],tsz,go[M][2],sz[M];
void Set(int &c, int lvl, ll x)
{
	if(!c) c=++tsz;
	sz[c]++;
	if(lvl<0) return;
	Set(go[c][(x>>lvl)&1],lvl-1,x);
}
ll Get(int c, int lvl, ll x)
{
	sz[c]--;
	if(lvl<0) return 0;
	int g=(x>>lvl)&1;
	if(sz[go[c][g]])
	{
		return Get(go[c][g],lvl-1,x);
	}
	else
	{
		return ((ll)1<<lvl)+Get(go[c][g^1],lvl-1,x);
	}
}
vector<ll> a[L];
int was[L];
int main()
{
	int n,i,j;ll x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		int lvl=0;
		for(j=0;j<L;j++) if((x>>j)&1) lvl=j;
		a[lvl].pb(x);
		Set(root[lvl],L-1,x);
	}
	for(j=0;j<L;j++) sort(a[i].begin(),a[i].end());
	x=0;vector<ll> sol;
	for(i=1;i<=n;i++)
	{
		bool ok=0;
		for(j=0;j<L;j++)
		{
			if((x>>j)&1) continue;
			if(was[j]<a[j].size())
			{
				ok=1;
				ll y=Get(root[j],L-1,x);
				sol.pb(x^y);
				x=y;
				//sol.pb(a[j][was[j]]);
				//x^=a[j][was[j]];
				//printf("%lld\n",a[j][was[j]]);
				was[j]++;
				break;
			}
		}
		if(!ok) return printf("No\n"),0;
	}
	printf("Yes\n");
	for(i=0;i<sol.size();i++) printf("%lld ",sol[i]);printf("\n");
	return 0;
}