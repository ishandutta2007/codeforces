#include <cmath>
#include <cstdio>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 7000;
const int MAXN = 100000;
const int MAXQ = 1000000;

bitset<MAXV>a[MAXN + 5], b[MAXV + 5], c[MAXV + 5];

int mu[MAXV + 5];
bool check(int x) {int s = sqrt(x); return s * s == x;}
void init() {
	for(int i=1;i<=MAXV;i++) mu[i] = 1;
	for(int i=4;i<=MAXV;i++) {
		if( !mu[i] || !check(i) ) continue;
		
		mu[i] = 0;
		for(int j=i;j<=MAXV;j+=i)
			mu[j] = 0;
	}
	for(int i=1;i<=MAXV;i++)
		for(int j=i;j<=MAXV;j+=i)
			b[j - 1][i - 1] = 1, c[i - 1][j - 1] = mu[j / i];
}

int main() {
	init(); int n, q;
	scanf("%d%d", &n, &q);
	for(int i=1,op,x,y,z,v;i<=q;i++) {
		scanf("%d", &op);
		if( op == 1 )
			scanf("%d%d", &x, &v), v--, a[x] = b[v];
		else if( op == 2 )
			scanf("%d%d%d", &x, &y, &z), a[x] = a[y] ^ a[z];
		else if( op == 3 )
			scanf("%d%d%d", &x, &y, &z), a[x] = a[y] & a[z];
		else {
			scanf("%d%d", &x, &v), v--;
			putchar(((a[x] & c[v]).count() & 1) + '0');
		}
	}
	puts("");
}