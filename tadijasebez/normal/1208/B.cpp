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
const int N=2050;
int a[N],cnt[N],c,d;
void Add(int x)
{
	cnt[x]++;
	if(cnt[x]==2) d++;
}
void Del(int x)
{
	cnt[x]--;
	if(cnt[x]==1) d--;
}
bool OK(){ return d==0;}
int main()
{
	map<int,int> id;
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]),a[i]=id.count(a[i])?id[a[i]]:id[a[i]]=++c;
	int ans=n;
	for(int j=n;j>0;j--)
	{
		Add(a[j]);
		if(OK()) ans=min(ans,j-1);
	}
	for(int j=n;j>0;j--) Del(a[j]);
	for(int i=1;i<=n;i++)
	{
		Add(a[i]);
		if(OK()) ans=min(ans,n-i);
		for(int j=n;j>i;j--)
		{
			Add(a[j]);
			if(OK()) ans=min(ans,j-i-1);
		}
		for(int j=n;j>i;j--) Del(a[j]);
	}
	printf("%i\n",ans);
	return 0;
}