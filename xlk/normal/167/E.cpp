#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int, int> ii;
typedef long long ll;
ll g[610][610], a[610][610];
int in[610], ot[610], e[610][610];
int n, m, p;
int q[610], b, f;
int s[610], t[610], sc, tc, tot;
bool st[610];
void inc(ll &x, ll y) {
	x = (x + y) % p;
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	fr(i,m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		in[y]++, ot[x]++;
		e[x][y]++;
	}
	fo(i,n)
	{
		if (!in[i])
			s[++sc] = i;
		if (!ot[i])
			t[++tc] = i;
		st[i] = !in[i] && !ot[i];
	}
	fo(i,n)
		if (!in[i])
			q[f++] = i, g[i][i] = 1;
	while (b < f) {
		int x = q[b++];
		fo(y,n)
			if (e[x][y]) {
				fo(i,sc)
					inc(g[s[i]][y], g[s[i]][x] * e[x][y] % p);
				in[y] -= e[x][y];
				if (!in[y])
					q[f++] = y;
			}
	}
	n = sc;
	fo(i,sc)
		fo(j,tc)
			a[i][j] = g[s[i]][t[j]];
	ll z = 1;
	fo(i,n)
	{
		for (int j = i + 1; j <= n; j++)
			while (a[j][i] != 0) {
				int d = a[i][i] / a[j][i];
				fo(k,n)
				{
					a[i][k] = (a[i][k] - a[j][k] * d) % p;
					swap(a[i][k], a[j][k]);
				}
				z = -z;
			}
		z = z * a[i][i] % p;
	}
	cout << (z + p) % p << endl;
	return 0;
}