#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> ii;
int N;
int s[200020];
int sa[200020], rk[200020], lcp[200020];
pair<ii, int> p[200020], q[200020];
int c[200020];
void RS() {
	int i;
	fr(i,N+5)
		c[i] = 0;
	fr(i,N)
		c[p[i].X.Y + 2]++;
	for (i = 1; i < N + 5; i++)
		c[i] += c[i - 1];
	fr(i,N)
	{
		q[c[p[i].X.Y + 1]] = p[i];
		c[p[i].X.Y + 1]++;
	}
	fr(i,N+5)
		c[i] = 0;
	fr(i,N)
		c[q[i].X.X + 2]++;
	for (i = 1; i < N + 5; i++)
		c[i] += c[i - 1];
	fr(i,N)
	{
		p[c[q[i].X.X + 1]] = q[i];
		c[q[i].X.X + 1]++;
	}
}
void SA() {
	int j, u = 0;
	fr(i,N)
		rk[i] = s[i];
	for (int t = 1; t < N; t *= 2) {
		fr(i,N)
			p[i] = make_pair(make_pair(rk[i], ((i + t >= N) ? -1 : rk[i + t])),
					i);
		RS();
		int sz = 0;
		fr(i,N)
		{
			if (i > 0 && p[i].X != p[i - 1].X)
				sz++;
			rk[p[i].Y] = sz;
		}
	}
	fr(i,N)
		sa[rk[i]] = i;
	fr(i,N)
		if (rk[i] != N - 1) {
			j = sa[rk[i] + 1];
			while (i + u < N && j + u < N && s[i + u] == s[j + u])
				u++;
			lcp[rk[i]] = u;
			if (u > 0)
				u--;
		}
}
int st[20][200010];
void rmq() {
	fr(i,N-1)
		st[0][i] = lcp[i];
	fr(i,17)
	{
		int t = (1 << i);
		fr(j,N-t)
			st[i + 1][j] = min(st[i][j], st[i][j + t]);
	}
}

int t[(1 << 18)];

void R(int x, int val) {
	for (int i = x; i < 1 << 18; i |= i + 1)
		t[i] += val;
}
int G(int x) {
	int _ = 0;
	for (int i = x; i > 0; i &= i - 1)
		_ += t[i - 1];
	return _;
}
vector<pair<ii, ii> > E;
int z[100010];
void Q(int id, int x, int y, int coef) {
	E.push_back(make_pair(ii(x, y), ii(id, coef)));
}
void Q(int id, int L, int R) {
	int i;
	int ps = rk[L];
	int d = R - L;
	int up = ps;
	for (i = 17; i >= 0; i--) {
		int t = (1 << i);
		if (up - t >= 0 && st[i][up - t] >= d)
			up -= t;
	}
	int dn = ps;
	for (i = 17; i >= 0; i--) {
		int t = (1 << i);
		if (st[i][dn] >= d)
			dn += t;
	}
	dn++;
	if (0 < +L - d) {
		Q(id, up, N / 2, 1);
		Q(id, up, N / 2 + L - d, -1);
		Q(id, dn, N / 2, -1);
		Q(id, dn, N / 2 + L - d, 1);
	}
	if (N / 2 + R + 1 < N - d + 1) {
		Q(id, up, N / 2 + R + 1, 1);
		Q(id, up, N - d + 1, -1);
		Q(id, dn, N / 2 + R + 1, -1);
		Q(id, dn, N - d + 1, 1);
	}
}
int h[200010];
pair<int, int> r[200010];
int main() {
	int n, q;
	scanf("%d", &n);
	fr(i,n)
		scanf("%d", &h[i]);
	n--;
	fr(i,n)
		h[i] -= h[i + 1];
	fr(i,n)
		h[n + i] = -h[i];
	N = 2 * n;
	fr(i,N)
		r[i] = make_pair(h[i], i);
	sort(r, r + N);
	int tmp = 0;
	fr(i,N)
	{
		if (i > 0 && r[i].X != r[i - 1].X)
			tmp++;
		s[r[i].Y] = tmp;
	}
	SA();
	rmq();
	scanf("%d", &q);
	fr(i,q)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		if (l == r)
			z[i] = n;
		else
			Q(i, l, r);
	}
	sort(E.begin(), E.end());
	int cur = 0;
	fr(i,E.size())
	{
		int x = E[i].X.X, y = E[i].X.Y, id = E[i].Y.X, u = E[i].Y.Y;
		while (cur < x) {
			R(sa[cur], 1);
			cur++;
		}
		z[id] += u * G(y);
	}
	fr(i,q)
		printf("%d\n", z[i]);
	return 0;
}