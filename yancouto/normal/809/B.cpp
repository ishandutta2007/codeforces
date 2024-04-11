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

char s[10];
bool inv = false;
bool tak(int x, int y) {
	if(inv) x = n + 1 - x;
	if(inv) y = n + 1 - y;
	printf("1 %d %d\n", x, y); fflush(stdout);
	scanf("%s", s);
	return s[0] == 'T';
}

bool simple_left(int x) {
	return tak(x, x + 1);
}

void ans(int x, int y) {
	printf("2 %d %d\n", x, y); fflush(stdout);
	exit(0);
}

int go(int i) {
	int d = 1;
	if(d > 0 && i == n) return 0;
	if(d < 0 && i == 1) return 0;
	if(tak(i + d, i)) return i + d;
	int not_ = i + d;
	int x = 1;
	while(not_ < n) {
		x = x * 2;
		if(tak(not_, not_ + 1)) not_ = 2 * not_ - i + 1 - 1;
		else {
			int l = 0;
			int r = min(2 * not_ - i + 1 - 1, n) - d * (not_ + 1);
			while(l < r) {
				int m = (l + r) / 2;
				if(tak(i + d * (m + 1), not_ + d)) l = m + 1;
				else r = m;
			}
			return not_ + d * (1 + l);
		}
	}
	return 0;
}

int main() {
	int i, j, k;
	scanf("%d %d", &n, &k);
	int l = 1, r = n;
	while(l < r) {
		int m = (l + r) / 2;
		if(simple_left(m)) r = m;
		else l = m + 1;
	}
	i = l;
	if(int j = go(i)) ans(i, j);
	else {
		inv = true;
		ans(i, n + 1 - go(n + 1 - i));
	}
}