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
const int N=1<<21;
int a[N],ans;
int fir[N],sec[N];
void push(int x, int i)
{
	if(fir[x]<i) sec[x]=fir[x],fir[x]=i;
	else if(sec[x]<i) sec[x]=i;
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	for(int i=1;i<=n;i++) push(a[i],i);
	for(int j=20;j>=0;j--)
	{
		for(int i=0;i<(1<<21);i++) if(i>>j&1)
		{
			int nxt=i^(1<<j);
			push(nxt,fir[i]);
			push(nxt,sec[i]);
		}
	}
	for(int i=1;i<=n-2;i++)
	{
		int tmp=0,need=0;
		for(int j=20;j>=0;j--)
		{
			if(a[i]>>j&1) tmp+=1<<j;
			else
			{
				need+=1<<j;
				if(sec[need]>i) tmp+=1<<j;
				else need-=1<<j;
			}
		}
		ans=max(ans,tmp);
	}
	printf("%i\n",ans);
	return 0;
}