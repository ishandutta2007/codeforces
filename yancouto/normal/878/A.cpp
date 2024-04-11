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

int fix[20], sw[20], val[20];

int main() {
	int i, j, n, x;
	char op;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf(" %c %d", &op, &x);
		for(j = 0; j < 10; j++) {
			if(op == '|') {
				if((x >> j) & 1) {
					fix[j] = 1;
					val[j] = 1;
				}
			} else if(op == '&') {
				if(!((x >> j) & 1)) {
					fix[j] = 1;
					val[j] = 0;
				}
			} else if(op == '^') {
				if((x >> j) & 1) {
					if(fix[j]) val[j] = !val[j];
					else sw[j] = !sw[j];
				}
			} else assert(0);
		}
	}
	printf("3\n");
	x = 0;
	for(j = 0; j < 10; j++)
		if(fix[j] && val[j])
			x |= (1 << j);
	printf("| %d\n", x);
	x = 0;
	for(j = 0; j < 10; j++)
		if(!(fix[j] && !val[j]))
			x |= (1 << j);
	printf("& %d\n", x);
	x = 0;
	for(j = 0; j < 10; j++)
		if(!fix[j] && sw[j])
			x |= (1 << j);
	printf("^ %d\n", x);
}