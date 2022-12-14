//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int n;
ll a[300000];

int q;

struct NODE
{
	ll mi;
	ll lazy;
};

NODE it1[600000], it2[600000];
int S;

void recalc(int now, NODE it[])
{
	if(now >= S) it[now].mi=it[now].lazy;
	else it[now].mi=min(it[now*2].mi, it[now*2+1].mi)+it[now].lazy;
}

void pushdown(int now, NODE it[])
{
	it[now*2].lazy+=it[now].lazy, it[now*2+1].lazy+=it[now].lazy, it[now].lazy=0;
	recalc(now*2, it), recalc(now*2+1, it);
}

void update(int now, int x, int y, int s, int e, ll v, NODE it[])
{
	if(x > y) return;
	if(x == s && y == e)
	{
		it[now].lazy+=v;
		recalc(now, it);
		return;
	}
	pushdown(now, it);
	update(now*2, x, min(y, (s+e)/2), s, (s+e)/2, v, it);
	update(now*2+1, max(x, (s+e)/2+1), y, (s+e)/2+1, e, v, it);
	recalc(now, it);
}

ll getmin(int now, int x, int y, int s, int e, NODE it[])
{
	if(x > y) return MAX2;
	if(x < 0) return 0;
	if(x == s && y == e) return it[now].mi;
	pushdown(now, it);
	return min(getmin(now*2, x, min(y, (s+e)/2), s, (s+e)/2, it), getmin(now*2+1, max(x, (s+e)/2+1), y, (s+e)/2+1, e, it));
}

void dodo(int x, int z)
{
	if(x == -1) return;
	if(x%2 == 0)
	{
		update(1, 0, n-1, 0, S-1, z, it1);
		update(1, x/2, n-1, 0, S-1, -z, it2);
	}
	else
	{
		update(1, 0, x/2, 0, S-1, z, it1);
	}
}

int main()
{
	int i, j, k, l;
	cin>>n;
	for(S=1;S<n;S*=2);
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	for(i=0;i<n;i++)
	{
		if(i%2 == 0)
		{
			update(1, i/2, n-1, 0, S-1, a[i], it1);
			update(1, i/2, n-1, 0, S-1, -a[i], it2);
		}
		else
		{
			update(1, i/2, n-1, 0, S-1, a[i], it2);
			update(1, i/2+1, n-1, 0, S-1, -a[i], it1);
		}
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		int type;
		scanf("%d", &type);
		int x, y, z;
		if(type == 1)
		{
			scanf("%d%d%d", &x, &y, &z);
			dodo(y, z);
			dodo(x-1, -z);
		}
		else
		{
			scanf("%d%d", &x, &y);
			int ans=0;
			if(x%2 == 0 && y%2 == 0)
			{
				ll res1=getmin(1, x/2, y/2-1, 0, S-1, it1);
				ll res2=getmin(1, x/2, y/2-1, 0, S-1, it2);
				ll res3=getmin(1, y/2, y/2, 0, S-1, it1);
				ll bad1=getmin(1, x/2-1, x/2-1, 0, S-1, it2);
				res1+=bad1, res3+=bad1, res2-=bad1;
				res1--, res3--;
				if(res1 >= 0 && res2 >= 0 && res3 == 0) ans=1;
			}
			else if(x%2 == 0 && y%2 == 1)
			{
				ll res1=getmin(1, x/2, y/2, 0, S-1, it1);
				ll res2=getmin(1, x/2, y/2-1, 0, S-1, it2);
				ll res3=getmin(1, y/2, y/2, 0, S-1, it2);
				ll bad1=getmin(1, x/2-1, x/2-1, 0, S-1, it2);
				res1+=bad1, res3-=bad1, res2-=bad1;
				res1--;
				if(res1 >= 0 && res2 >= 0 && res3 == 0) ans=1;
			}
			else if(x%2 == 1 && y%2 == 0)
			{
				ll res1=getmin(1, x/2, y/2-1, 0, S-1, it2);
				ll res2=getmin(1, x/2+1, y/2-1, 0, S-1, it1);
				ll res3=getmin(1, y/2, y/2, 0, S-1, it1);
				ll bad1=getmin(1, x/2, x/2, 0, S-1, it1);
				res1+=bad1, res3-=bad1, res2-=bad1;
				res1--;
				if(res1 >= 0 && res2 >= 0 && res3 == 0) ans=1;
			}
			else
			{
				ll res1=getmin(1, x/2, y/2-1, 0, S-1, it2);
				ll res2=getmin(1, x/2+1, y/2, 0, S-1, it1);
				ll res3=getmin(1, y/2, y/2, 0, S-1, it2);
				ll bad1=getmin(1, x/2, x/2, 0, S-1, it1);
				res1+=bad1, res3+=bad1, res2-=bad1;
				res1--, res3--;
				if(res1 >= 0 && res2 >= 0 && res3 == 0) ans=1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
//*/