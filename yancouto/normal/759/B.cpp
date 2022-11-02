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
int t[112345];
int memo[112345];
int solve(int i) {
	if(i < 0) return 0;
	int &ret = memo[i];
	if(ret != -1) return ret;
	ret = 20 + solve(i - 1);
	if(t[0] > t[i] - 90) ret = min(ret, 50);
	else {
		int l = 0, r = i - 1;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if(t[m] <= t[i] - 90) l = m;
			else r = m - 1;
		}
		ret = min(ret, 50 + solve(l));
	}
	if(t[0] > t[i] - 1440) ret = min(ret, 120);
	else {
		int l = 0, r = i - 1;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if(t[m] <= t[i] - 1440) l = m;
			else r = m - 1;
		}
		ret = min(ret, 120 + solve(l));
	}
	return ret;
}

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(t[i]);
	memset(memo, -1, sizeof memo);
	//for(i = 0; i < n; i++) printf("[%3d] solve(%d) = %d\n", t[i], i, solve(i));
	printf("%d\n", solve(0));
	for(i = 1; i < n; i++) printf("%d\n", solve(i) - solve(i - 1));
}