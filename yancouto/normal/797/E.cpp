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

const int N = 100009, Q = 300;

int n;
int a[Q][N];
int b[N];

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(b[i]);
	for(j = 0; j < Q; j++)
		for(i = 0; i < n; i++)
			a[j][i] = b[i] + j;
	for(j = 0; j < Q; j++)
		for(i = n - 1; i >= 0; i--) {
			if(i + a[j][i] >= n) a[j][i] = 1;
			else a[j][i] = 1 + a[j][i + a[j][i]];
		}
	int q, p, k;
	rd(q);
	while(q--) {
		rd(p); rd(k);
		if(k < Q) printf("%d\n", a[k][p - 1]);
		else {
			int ct = 0; p--;
			for(; p < n; ct++) {
				p += b[p] + k;
			}
			printf("%d\n", ct);
		}
	}
}