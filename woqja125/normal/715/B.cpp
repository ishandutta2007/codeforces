#include<stdio.h>
#include<vector>
struct weight
{
	long long s, e;
	weight(long long S, long long E=1e15):s(S), e(E){}
	weight(){ s=e=1e15; }
};
struct edge
{
	int s, t;
	weight w;
	edge(int S=0, int T=0, weight W=weight()):s(S), t(T), w(W){}
};
edge map[10001];
bool chk[10001];
weight D[1001];
int p[1001];
int pr[1001];
weight getmin(const weight &A, const weight &B, int &p, int a, int b)
{
	long long e2 = A.e>B.e?B.e:A.e;
	if(A.s <= B.s)
	{
		p = a;
		return weight(A.s, e2);
	}
	p = b;
	return weight(B.s, e2);
}
weight operator+(const weight &A, const weight &B)
{
	return weight(A.s+B.s, A.e+B.e);
}
int main()
{
	int n, m, a, b, w, s, t;
	long long l;
	scanf("%d%d%lld%d%d", &n, &m, &l, &s, &t);
	for(int i=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &w);
		weight W;
		if(w==0) W = weight(1);
		else W = weight(w, w);
		map[i] = edge(a, b, W);
		if(w==0)
		{
			chk[i] = 1;
		}
	}
	for(int i=0; i<n; i++) D[i] = weight();
	D[s] = weight(0, 0);
	p[s] = -1;
	for(int T=0; T<=n; T++)
	{
		for(int i=0; i<m; i++)
		{
			int t = map[i].t;
			int s = map[i].s;
			D[t] = getmin(D[t], D[s]+map[i].w, p[t], p[t], s);
			if(p[t] == s) pr[t] = i;
			D[s] = getmin(D[s], D[t]+map[i].w, p[s], p[s], t);
			if(p[s] == t) pr[s] = i;
		}
	}
	if(D[t].s <= l && l <= D[t].e)
	{
		printf("YES\n");
		int x = t;
		while(p[x] != -1)
		{
			if(chk[pr[x]])
			{
				if(l-1 <= D[p[x]].e)
				{
					map[pr[x]].w.s = 1;
					l--;
				}
				else
				{
					map[pr[x]].w.s = l-D[p[x]].e;
					l = D[p[x]].e;
				}
				chk[pr[x]] = 0;
			}
			else
			{
				l -= map[pr[x]].w.s;
			}
			x = p[x];
		}
		for(int i=0; i<m; i++)
		{
			if(chk[i])
			{
				printf("%d %d %lld\n", map[i].s, map[i].t, 10000000000000000ll);
			}
			else
				printf("%d %d %lld\n", map[i].s, map[i].t, map[i].w.s);
		}
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}