#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
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

const int N = 212345;

int mnl[N], mnr[N], mxl[N], mxr[N];

ll go(vector<pii> p) {
	if(p.empty()) return 0;
	int i, j;
	sort(p.begin(), p.end(), [](pii a, pii b) { return a.x + a.y < b.x + b.y; });
	int n = p.size();
	mxl[0] = mnl[0] = p[0].x - p[0].y;
	for(i = 1; i < n; i++) {
		mnl[i] = min(mnl[i - 1], p[i].x - p[i].y);
		mxl[i] = max(mxl[i - 1], p[i].x - p[i].y);
	}
	//for(i = 0; i < n; i++)
	//	printf("[%d] mn %d mx %d\n", i, mnl[i], mxl[i]);
	mnr[n - 1] = mxr[n - 1] = p[n - 1].x - p[n - 1].y;
	for(i = n - 2; i >= 0; i--) {
		mnr[i] = min(mnr[i + 1], p[i].x - p[i].y);
		mxr[i] = max(mxr[i + 1], p[i].x - p[i].y);
	}
	//for(i = 0; i < n; i++)
	//	printf("[%d] mnr %d mxr %d\n", i, mnr[i], mxr[i]);
	i = 0;
	ll ans = 0;
	for(int d = p[0].x + p[0].y; d <= p[n - 1].x + p[n - 1].y; d++) {
		j = i - 1;
		while(j + 1 < n && p[j + 1].x + p[j + 1].y == d)
			j++;
		//printf("d %d (i, j) (%d, %d)\n", d, i, j);
		if(i > 0 && j < n && (abs(d) % 2) != (abs(p[0].x + p[0].y) % 2)) {
			//printf("max(%d, %d) + 1 to min(%d, %d) - 1\n", mnl[i - 1], mnr[j + 1], mxl[i - 1], mxr[j + 1]);
			int l = max(mnl[i - 1], mnr[j + 1]);
			int r = min(mxl[i - 1], mxr[j + 1]);
			//printf("(l, r) (%d, %d)\n", l, r);
			if(l <= r) {
				assert(((r - l) % 2) == 0);
				ans += ll(r - l) / 2;
			}
		}
		i = j + 1;
	}
	return ans;
}

pii p[N];
int main() {
	int i, n;
	rd(n);
	vector<pii> odd, even;
	for(i = 0; i < n; i++) {
		rd(p[i].x), rd(p[i].y);
		if((p[i].x + p[i].y) % 2)
			odd.pb(p[i]);
		else
			even.pb(p[i]);
	}
	printf("%lld\n", go(odd) + go(even));
}