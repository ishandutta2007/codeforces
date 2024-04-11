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


int main() {
	double h;
	int i, n;
	scanf("%d %lf", &n, &h);
	double hp2 = 0;
	for(i = 0; i < n - 1; i++) {
		double hn2 = hp2 + h * h / (1. * n);
		printf("%.15f ", sqrt(hn2));
		hp2 = hn2;
	}
	putchar('\n');
}