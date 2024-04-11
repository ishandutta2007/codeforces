#include <bitset>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct matrix{
	bitset<150>b[150]; matrix() {memset(b, 0, sizeof b);}
	
	friend matrix operator * (matrix A, matrix B) {
		matrix C;
		for(int i=0;i<n;i++)
			for(int k=0;k<n;k++)
				if( A.b[i][k] ) C.b[i] |= B.b[k];
		return C;
	}
}A, B, I;

matrix P[60];
bool check(int l, int r) {
	if( l == r ) return false;
	
	int k = r - l, nw = l, i; P[0] = B;
	for(i = 1; (1<<i) <= k; i++) P[i] = P[i - 1] * P[i - 1];
	for(i--; i >= 0; i--) {
		if( nw > r - (1 << i) ) continue;
		
		matrix T = A * P[i];
		if( !T.b[0][n - 1] )
			A = T, nw += (1 << i);
	}
	
	if( nw != r ) {
		printf("%d\n", nw + 1);
		return true;
	} else return false;
}

struct edge{
	int a, b, d; edge() {}
	edge(int _a, int _b, int _d) : a(_a), b(_b), d(_d) {}
	friend bool operator < (const edge &a, const edge &b) {
		return a.d < b.d;
	}
}e[155];

int main() {
	int m; scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].d), e[i].a--, e[i].b--;
	e[m].a = n - 1, e[m].b = n - 1, e[m].d = 0;
	sort(e, e + m + 1);
	
	for(int i=0;i<n;i++) I.b[i][i] = 1; A = I;
	
	int lst = 0;
	for(int i=0;i<=m;i++) {
		if( check(lst, e[i].d) ) return 0;
		lst = e[i].d, B.b[e[i].a][e[i].b] = 1;
	}
	if( check(lst, lst + n) ) return 0;
	
	puts("Impossible");
}