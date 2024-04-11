#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int st[2000], sn;
char str[200];
int dig[12];
int main() {
	int i, j, n;
	scanf("%d %s", &n, str);
	for(i = 0; i < n; i++)
		for(j = 2; j <= (str[i] - '0'); j++)
			dig[j]++;
	for(i = 0; i < dig[7]; i++) putchar('7');
	for(i = 2; i <= 7; i++) dig[i] -= dig[7];
	for(i = 0; i < dig[5]; i++) putchar('5');
	for(i = 2; i <= 5; i++) dig[i] -= dig[5];	
	dig[3] += 2 * dig[9] + dig[6];
	dig[2] += 3 * dig[8] + dig[6] + 2 * dig[4];
	for(i = 0; i < dig[3]; i++) putchar('3');
	dig[2] -= dig[3];
	for(i = 0; i < dig[2]; i++) putchar('2');
	putchar('\n');
}