#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

// k x n
ull m[2][5003], acc[2][5003];
int main() {
	int n, a, b, k;
	scanf("%d %d %d %d", &n, &a, &b, &k);
	if(a > b) {
		a = n - a + 1;
		b = n - b + 1;
	}
	int i, j;
	for(j = 1; j < b; j++) {
		m[0][j] = 1;
		acc[0][j] = mod(1 + acc[0][j - 1]);
	}
	for(i = 1; i <= k; i++)
		for(j = 1; j < b; j++) {
			m[i%2][j] = mod(acc[(i - 1)%2][b - 1] - acc[(i - 1)%2][max(j - (b - j) + 1, 1) - 1] + modn);
			m[i%2][j] = mod(m[i%2][j] - m[(i - 1)%2][j] + modn);
			acc[i%2][j] = mod(acc[i%2][j - 1] + m[i%2][j]);
		}
	printf("%d\n", (int)m[k%2][a]);
	return 0;
}