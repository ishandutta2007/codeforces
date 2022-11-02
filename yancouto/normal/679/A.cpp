#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};


char s[100];
int main() {
	for(int x = 2; x <= 100; x++) {
		int i, j, n;
		int ct = 0, p;
		for(int i = 0; i < 19; i++) {
			printf("%d\n", a[i]); fflush(stdout);
			scanf("%s", s);
			if(s[0] == 'y') ct++, p = a[i];
		}
		if(ct >= 2) puts("composite");
		else if(ct == 0 || p * p > 100) puts("prime");
		else {
			printf("%d\n", p*p); fflush(stdout);
			scanf("%s", s);
			if(s[0] == 'y') puts("composite");
			else puts("prime");
		}
	}
}