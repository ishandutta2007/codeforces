#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

const int maxd = 128; 

int n, x; 
db a[maxd][maxd]; 
db b[maxd][maxd]; 
db s[maxd][maxd]; 
db t[maxd][maxd]; 
db p[maxd]; 

void mul(db a[maxd][maxd],db b[maxd][maxd],db c[maxd][maxd]) {
	memset(c, 0, sizeof(s)); 
	for (int i = 0; i < maxd; ++i) 
		for (int j = 0; j < maxd; ++j) 
			for (int k = 0; k < maxd; ++k) 
				c[i][j] += a[i][k] * b[k][j]; 
}

void Mov(db a[maxd][maxd],db b[maxd][maxd]) {
	for (int i = 0; i < maxd; ++i) 
		for (int j = 0; j < maxd; ++j) 
			b[i][j] = a[i][j]; 
}

int main() {
	memset(a, 0, sizeof(a)); 
	memset(s, 0, sizeof(s)); 
	scanf( "%d%d", &n, &x ); 
	for (int i = 0; i <= x; ++i) scanf( "%lf", &p[i] ); 
	for (int i = 0; i < maxd; ++i) 
		for (int j = 0; j <= x; ++j) 
			a[i][i^j] = p[j]; 
	for (int i = 0; i < maxd; ++i) s[i][i] = 1; 
	while (n > 0) {
		if (n % 2 == 1) {
			mul(s,a,t); 
			Mov(t,s); 
		}
		mul(a,a,t); 
		Mov(t,a); 
		n /= 2; 
	}
	printf( "%.12f\n", 1-s[0][0] ); 
	return 0;
}