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

template<class num> inline void read(num &x) {
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
const int N = 112345, L = 35;
int f[L][N], m[L][N], ansm[N]; ll s[L][N], anss[N];

int main() {
	int i, j; ll k;
	read(n); read(k);
	for(i = 0; i < n; i++) read(f[0][i]);
	for(i = 0; i < n; i++) read(s[0][i]), m[0][i] = s[0][i];
	for(j = 1; j < L; j++)
		for(i = 0; i < n; i++) {
			f[j][i] = f[j - 1][f[j - 1][i]];
			s[j][i] = s[j - 1][i] + s[j - 1][f[j - 1][i]];
			m[j][i] = min(m[j - 1][i], m[j - 1][f[j - 1][i]]);
		}
	for(i = 0; i < n; i++) {
		ansm[i] = INT_MAX;
		int x = i;
		for(j = 0; j < L; j++)
			if((1ll << j) & k)
				anss[i] += s[j][x],
				ansm[i] = min(ansm[i], m[j][x]),
				x = f[j][x];
	}
	for(i = 0; i < n; i++) printf("%lld %d\n", anss[i], ansm[i]);
}