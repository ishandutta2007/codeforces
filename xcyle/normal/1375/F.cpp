#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
long long a, b, c, x, y;
void work()
{
	long long ta = a, tb = b, tc = c;
	if(ta > tb) swap(ta, tb);
	if(tb > tc) swap(tb, tc);
	if(ta > tb) swap(ta, tb);
	x = tb - ta, y = tc - tb;
}
int ip;
void del(long long x)
{
	printf("%lld\n", x);
	fflush(stdout);
	scanf("%d", &ip);
	if(ip == 1) a += x;
	if(ip == 2) b += x;
	if(ip == 3) c += x;
	work();
}
int main()
{
	scanf("%d%d%d", &a, &b, &c);
	work();
	printf("First\n");
	fflush(stdout);
	del(30000000000);
	del(20000000000);
	del(x - y);
	int tmp;
	if(ip == 1) tmp = a;
	else if(ip == 2) tmp = b;
	else tmp = c;
	if(tmp >= a && tmp >= b && tmp >= c) del(x);
	else
	{
		del(x);
		del(5 * x);
		del(x);
	}
	return 0;
}