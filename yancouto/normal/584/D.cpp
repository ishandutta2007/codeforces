#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

bool prime(int x) {
	for(int i = 2; i * i <= x; i++)
		if(!(x % i))
			return false;
	return true;
}

void do_2(int x) {
	int i, j;
	for(i = 2; i < 300; i++)
		if(prime(i))
			for(j = 2; j < 300; j++)
				if(prime(j) && i + j == x) {
					printf("%d %d\n", i, j);
					exit(0);
				}
}

int main() {
	int x;
	scanf("%d", &x);
	if(prime(x)) { printf("1\n%d\n", x); return 0; }
	int y = x;
	while(!prime(x)) x--;
	if(prime(y - x)) { printf("2\n%d %d\n", x, y - x); return 0; }
	printf("3\n%d ", x);
	do_2(y - x);
}