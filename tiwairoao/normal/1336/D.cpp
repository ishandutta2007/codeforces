#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define fi first
#define se second
#define pr make_pair

typedef pair<int, int> pii;

const int N = 5000;

int g[N + 5];
int f(int n) {
	return n * (n - 1) * (n - 2) / 6;
}
void init() {
	for(int i=2;i<=100;i++)
		g[f(i + 1) - f(i)] = i;
}

pii nw;
pii add(int x) {
	printf("+ %d\n", x), fflush(stdout);
	pii p; scanf("%d%d", &p.fi, &p.se);
	pii t = nw; nw = p;
	return pr(p.fi - t.fi, p.se - t.se);
}

int a[105], c[105], n;

void print() {
	printf("!");
	for(int i=1;i<=n;i++)
		printf(" %d", a[i]);
	puts(""), fflush(stdout);
}

int main() {
	init(), scanf("%d%d%d", &n, &nw.fi, &nw.se);
	
	pii p1 = add(1), p2 = add(2), p3 = add(3), q1 = add(1);
	a[1] = ((p1.fi == 0) ? (q1.fi != 0) : g[p1.fi]);
	a[3] = ((p3.fi == 0) ? (p2.se != 0) : g[p3.fi]);
	a[2] = q1.se / (a[3] + 1) - 1;
	
	int x = p3.se - (a[1] + 1) * (a[2] + 1);
	for(int i=4;i<n;i++) {
		pii p = add(i);
		a[i] = ((p.fi == 0) ? (x != 0) : g[p.fi]);
		x = p.se - (a[i - 2] + 1)*(a[i - 1] + 1);
	}
	a[n] = x / (a[n - 2] + 1);
	
	print();
}
/*
5
1 6
2 9
2 15
5 21
8 29
8 45
*/