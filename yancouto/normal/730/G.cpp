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


const int N = 2e2+7;
int n;

int s;
int d;
set<pii> mp;
set<pii>::iterator it;

int main() {
	int i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &s, &d);

		it = mp.lower_bound(pii(s, 0));
		pii res = pii(0, 0);
		if (it == mp.end() || s + d <= it->first) {
			bool ok = 1;
			if (it != mp.begin()) {
				--it;
				if (it->second > s)
					ok = 0;
			}
			if (ok)
				res = pii(s, s+d);
		}
		
		if (res.first == 0) {
			int ls = 1;
			for (pii x : mp) {
				if (x.first - ls >= d)
					break;
				ls = x.second;
			}
			res = pii(ls, ls+d);
		}
		mp.insert(res);
		printf("%d %d\n", res.first, res.second-1);
	}
}