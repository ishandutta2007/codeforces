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

int en = 1;
const int N = 112345 * 30;

int tr[N][2], sz[N];

int main() {
	int i, j, op, p, l;
	rd(n);
	for(i = 0; i < n; i++) {
		rd(op); rd(p);
		if(op == 3) {
			rd(l);
			int v = 0;
			int tot = 0;
			for(j = 30; j >= 0; j--) {
				int b = (((l ^ p) >> j) & 1);
				if((l >> j) & 1) tot += sz[tr[v][!b]];
				if(!tr[v][b]) break;
				v = tr[v][b];
			}
			printf("%d\n", tot);
		} else {
			int x = (op == 1? 1 : -1);
			int v = 0;
			for(j = 30; j >= 0; j--) {
				if(!tr[v][(p >> j) & 1])
					tr[v][(p >> j) & 1] = en++;
				v = tr[v][(p >> j) & 1];
				sz[v] += x;
			}
		}
	}
}