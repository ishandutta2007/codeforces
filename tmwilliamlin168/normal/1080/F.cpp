#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define P pair<int, int>
#define fi(x) (x).first
#define se(x) (x).second
#define mkp(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 3e5+10, lgN = 29, INF = 2e9;

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct segTree
{
	struct node { int l, r, w, flg; } sgt[N*lgN];
	int p = 0, rt[N] = {0};
	void insert(int &i, int b, int e, int k, int x)
		{
			sgt[++p] = sgt[i]; i = p;
			if(b==e)
			{
				sgt[i].w = sgt[i].w ? min(sgt[i].w, x) : x;
				return;
			}
			int mid = (b+e)>>1;
			if(k<=mid) insert(sgt[i].l, b, mid, k, x);
			else insert(sgt[i].r, mid+1, e, k, x);
			sgt[i].w = max(sgt[sgt[i].l].w, sgt[sgt[i].r].w);
		}
	int query(int i, int b, int e, int l, int r)
		{
//			printf("q: %d [%d, %d] [%d, %d]\n", i, b, e, l, r);
			if(e < l || r < b) return 0;
			if(i == 0) return INF;
			if(l <= b && e <= r) return sgt[i].w;
			int mid = (b+e)>>1, lc = sgt[i].l, rc = sgt[i].r;
			return max(query(lc, b, mid, l, r),
					   query(rc, mid+1, e, l, r));
		}
	void walk(int i, int b, int e, int dep)
		{
			if(!i) return;
			int mid = (b+e)>>1, lc = sgt[i].l, rc = sgt[i].r;
			if(b != e) walk(lc, b, mid, dep+1);
			for(int i = 0; i < dep; i++) printf("  ");
			printf("%d[%d,%d]w=%d\n", i, b, e, sgt[i].w);
			if(b != e) walk(rc, mid+1, e, dep+1);
		}
} t;

struct seg { int l, r, p; } a[N];
bool comp(seg a, seg b) { return a.l < b.l; }
int n, m, k, rt[N];
int bin(int x) //min_k { l[k] >= x }
{
	int l = 1, r = k, ret = -1;
	while(l <= r)
	{
		int mid = (l+r)>>1;
		if(a[mid].l >= x) ret = mid, r = mid-1;
		else l = mid+1;
	}
	return ret;
}

int main()
{
//	freopen("std.in", "r", stdin);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= k; i++)
	{
		a[i].l = read(); a[i].r = read(); a[i].p = read();
	}
	sort(a + 1, a + k + 1, comp); t.sgt[0].w = INF;
	for(int i = k; i; i--)
	{
		rt[i] = rt[i+1];
		t.insert(rt[i], 1, n, a[i].p, a[i].r);
//		printf("rt[%d]\n", i);
//		t.walk(rt[i], 1, n, 0);
	}
	for(int i = 1; i <= m; i++)
	{
		int a = read(), b = read(), x = read(), y = read();
		int lb = bin(x);
		if(lb == -1 || t.query(rt[lb], 1, n, a, b) > y) printf("no\n");
		else printf("yes\n");
		fflush(stdout);
	}
		
}