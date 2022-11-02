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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;

ll a[1123][12];

int main() {
	int i, j, k, g;
	rd(n);
	if(n > 40) {
		printf("0\n");
		return 0;
	}
	for(i = 0; i < n; i++)
		for(j = 0; j < 5; j++)
			rd(a[i][j]);
	vector<int> good;
	for(i = 0; i < n; i++) {
		bool bad = false;
		for(j = 0; j < n; j++)
			if(j != i)
				for(k = 0; k < n; k++) {
					if(k == i || k == j) continue;
					ll tot = 0;
					for(g = 0; g < 5; g++)
						tot += (a[j][g] - a[i][g]) * (a[k][g] - a[i][g]);
					if(tot > 0) bad = true;
				}
		if(!bad) good.pb(i);
	}
	printf("%d\n", int(good.size()));
	if(good.empty()) return 0;
	for(int x : good) printf("%d ", x + 1);
	putchar('\n');
}