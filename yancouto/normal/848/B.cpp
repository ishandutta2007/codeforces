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

const int N = 212345;
int ex[N], ey[N];
struct dnc {
	int g, p, t, i;
	void read(int i_) { i = i_; rd(g); rd(p); rd(t); }
	bool operator < (dnc o) const {
		return p < o.p;
	}
};

vector<dnc> buck[N + N];

dnc d[N];

int main() {
	int i, j;
	int n, W, H;
	rd(n);
	rd(W); rd(H);
	for(i = 0; i < n; i++) { d[i].read(i); buck[d[i].t - d[i].p + N].pb(d[i]); }
	for(i = 0; i < N + N; i++) {
		if(buck[i].empty()) continue;
		vector<dnc> dx, dy;
		for(dnc d : buck[i]) {
			if(d.g == 1)
				dx.pb(d);
			else
				dy.pb(d);
		}
		sort(dx.begin(), dx.end());
		sort(dy.begin(), dy.end());
		for(int g = 0; g < dx.size(); g++) {
			dnc d = dx[g];
			int v = dx.size() - g;
			int h = dy.size();
			if(h == 0) {
				ex[d.i] = d.p;
				ey[d.i] = H;
				continue;
			}
			if(h > v) h = v;
			if(v > h + 1) v = h + 1;
			if(v == h + 1) {
				ex[d.i] = dx[g + v - 1].p;
				ey[d.i] = H;
			} else {
				assert(v == h);
				ex[d.i] = W;
				ey[d.i] = dy[h - 1].p;
			}
		}
		for(int g = 0; g < dy.size(); g++) {
			dnc d = dy[g];
			int v = dx.size();
			int h = dy.size() - g;
			if(v == 0) {
				ex[d.i] = W;
				ey[d.i] = d.p;
				continue;
			}
			if(v > h) v = h;
			if(h > v + 1) h = v + 1;
			if(h == v + 1) {
				ex[d.i] = W;
				ey[d.i] = dy[g + h - 1].p;
			} else {
				assert(v == h);
				ex[d.i] = dx[v - 1].p;
				ey[d.i] = H;
			}
		}
	}
	for(i = 0; i < n; i++)
		printf("%d %d\n", ex[i], ey[i]);
}