#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, tot = 1, s, t, z;
int e[100020][4];
int v[100020], a[100020], d[100020], q[500020], r[100020], p[100020], h[100020];
bool in[100020];
void add(int x, int y, int z, int c) {
	tot++;
	e[tot][1] = y;
	e[tot][2] = z;
	e[tot][3] = c;
	e[tot][0] = h[x];
	h[x] = tot;

	tot++;
	e[tot][1] = x;
	e[tot][2] = 0;
	e[tot][3] = -c;
	e[tot][0] = h[y];
	h[y] = tot;
}
bool spfa() {
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	int b = 0, f = 1;
	q[1] = s;
	memset(in, 0, sizeof(in));
	while (b < f) {
		int i = q[++b];
		in[i] = 0;
		for (int k = h[i]; k; k = e[k][0])
			if (e[k][2]) {
				int j = e[k][1];
				if (d[i] + e[k][3] >= d[j])
					continue;
				d[j] = d[i] + e[k][3], p[j] = k;
				if (!in[j])
					in[j] = 1, q[++f] = j;
			}
	}
	if (d[t] > 0)
		return 0;
	z += d[t];
	for (int k = t; k; k = e[k ^ 1][1])
		k = p[k], e[k][2]--, e[k ^ 1][2]++;
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	t = n * 3 + 1;
	add(s,1,m,0);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		add(i,i+n,1,__builtin_popcount(a[i]));
		add(i+n,i+2*n,1,-100000);
		add(i+2*n,t,1,0);
		if (i<n)
		{
			add(i+2*n,i+1,1,0);
			add (i,i+1,100000,0);
		}
	}
	for (int i = 1, j; i <= n; i++) {
		for (j = i + 1; j <= n && a[i] - a[j]; j++)
		;
		if (j <= n)
		{
			add(i+2*n,j+n,1,0);
			v[i] = j;
		}
		else
		tot += 2;
	}
	while (spfa())
	;
	m = n;
	for (int i = 1; i <= n; i++)
	if (e[n * 10 + i * 2 - 1][2])
	m--;
	printf("%d %d\n", m + n, (z % 100000 + 100000) % 100000);
	memset(in, 0, sizeof(in));
	for (int i = 1; i <= n; i++) {
		int w = r[i];
		if (!w) {
			for (w = 97; in[w]; w++)
			;
			in[w] = 1, printf("%c=%d\n", w, a[i]);
		}
		printf("print(%c)\n", w);
		if (e[n * 10 + i * 2 - 1][2])
		r[v[i]] = w;
		else
		in[w] = 0;
	}
	return 0;
}