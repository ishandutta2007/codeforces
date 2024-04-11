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
const int N=1000050;
const int M=2*N;
vector<int> a[N];
struct SegmentTree
{
	ll sum[M];
	SegmentTree(){}
	void Set(int l, int r, int f)
	{
		//printf("(%i %i) %i\n",l,r,f);
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) sum[l++]+=f;
			if(r%2==0) sum[r--]+=f;
		}
	}
	ll Get(int i){ ll ans=0;for(i+=N;i;i>>=1) ans+=sum[i];return ans;}
} ST;
int main()
{
	int n,w;
	scanf("%i %i",&n,&w);
	for(int j=1;j<=n;j++)
	{
		int l;
		scanf("%i",&l);
		int mv=w-l;
		stack<pair<int,pair<int,int>>> intervals;
		a[j].resize(l+1);
		for(int i=1;i<=l;i++)
		{
			scanf("%i",&a[j][i]);
			int r=i+mv,l=i+mv;
			while(intervals.size() && intervals.top().first<a[j][i] && intervals.top().second.second>=i)
			{
				pair<int,pair<int,int>> tmp=intervals.top();
				//printf("%i %i %i\n",tmp.first,tmp.second.first,tmp.second.second);
				intervals.pop();
				if(tmp.second.first<i)
				{
					tmp.second.second=i-1;
					intervals.push(tmp);
					l=i;
				}
				else l=tmp.second.first;
			}
			if(intervals.empty()) l=i;
			intervals.push({a[j][i],{l,r}});
		}
		while(intervals.size())
		{
			pair<int,pair<int,int>> tmp=intervals.top();
			intervals.pop();
			if(tmp.first<0)
			{
                ckmn(tmp.second.second,l);
                ckmx(tmp.second.first,mv+1);
			}
			ST.Set(tmp.second.first,tmp.second.second,tmp.first);
		}
	}
	for(int i=1;i<=w;i++) printf("%lld ",ST.Get(i));
	return 0;
}