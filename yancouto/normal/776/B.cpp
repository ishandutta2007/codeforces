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
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
const int N = 212345;
int co[N];

int main() {
	int i, j;
	scanf("%d", &n);
	if(n <= 2) {
		puts("1");
		for(i = 0; i < n; i++) printf("1 ");
	} else {
		puts("2");
		for(i = 2; i < N; i++)
			if(!co[i])
				for(j = 2 * i; j < N; j += i)
					co[j] = 1;
		for(i = 2; i <= n + 1; i++)
			printf("%d ", 1 + co[i]);
	}
	putchar('\n');
}