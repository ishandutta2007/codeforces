#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

int main() {
	int a, b;
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 0; a * i <= n; i++)
		if(!((n - a * i) % b)) {
			int j = (n - a * i) / b;
			for(int k = 0; k < i; k++) {
				for(int l = 0; l < a - 1; l++)
					printf("%d ", k * a + l + 1 + 1);
				printf("%d ", k * a + 1);
			}
			for(int k = 0; k < j; k++) {
				for(int l = 0; l < b - 1; l++)
					printf("%d ", i * a + k * b + l + 1 + 1);
				printf("%d ", i * a + k * b + 1);
			}
			putchar('\n');
			return 0;
		}
	puts("-1");
}