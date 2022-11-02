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

bool leap(int y) {
	if(!(y % 400)) return true;
	if(!(y % 100)) return false;
	return !(y % 4);
}

int main() {
	int i, j, n;
	scanf("%d", &n);
	j = 1 + leap(n);
	for(i = n + 1; ; i++) {
		if(j == 0 && leap(i) == leap(n)) {
			printf("%d\n", i);
			return 0;
		}
		j++;
		if(leap(i)) j++;
		j %= 7;
	}
}