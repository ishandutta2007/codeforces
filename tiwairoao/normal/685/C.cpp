#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = ll(3E18);
const int dx[4] = {1, 1, 1, -1};
const int dy[4] = {1, 1, -1, 1};
const int dz[4] = {1, -1, 1, 1};

ll le[4], ri[4];
ll a1, b1, c1;
bool get() {
	for(int i=0;i<4;i++)
		if( le[i] > ri[i] ) return false;
	
	a1 = le[1], b1 = le[2], c1 = le[3];
	if( a1 + b1 + c1 > ri[0] ) return false;
	else {
		if( a1 + b1 + c1 < le[0] ) {
			if( ri[1] + b1 + c1 >= le[0] ) {
				a1 = le[0] - b1 - c1;
				return true;
			} else {
				a1 = ri[1];
				if( a1 + ri[2] + c1 >= le[0] ) {
					b1 = le[0] - a1 - c1;
					return true;
				} else {
					b1 = ri[2];
					if( a1 + b1 + ri[3] >= le[0] ) {
						c1 = le[0] - a1 - b1;
						return true;
					} else return false;
				}
			}
		} else return true;
	}
}

ll lb[4], ub[4];
ll ansx, ansy, ansz;
bool check(ll d) {
	for(int o=0;o<=1;o++) {
		le[0] = (lb[0] - d) - 3*o, ri[0] = (ub[0] + d) - 3*o;
		for(int i=1;i<4;i++) le[i] = (lb[i] - d) - o, ri[i] = (ub[i] + d) - o;
		for(int i=0;i<4;i++) le[i] = ceil((long double)le[i] / 2), ri[i] = floor((long double)ri[i] / 2);
		if( get() ) {
			ll a = 2*a1 + o, b = 2*b1 + o, c = 2*c1 + o;
			ansx = (a + b) / 2, ansy = (a + c) / 2, ansz = (b + c) / 2;
			return true;
		}
	}
	return false;
}
void solve() {
	int n; scanf("%d", &n);
	for(int i=0;i<4;i++) lb[i] = -INF, ub[i] = INF;
	for(int i=1;i<=n;i++) {
		ll x, y, z; scanf("%lld%lld%lld", &x, &y, &z);
		for(int j=0;j<4;j++) {
			lb[j] = max(lb[j], dx[j]*x + dy[j]*y + dz[j]*z);
			ub[j] = min(ub[j], dx[j]*x + dy[j]*y + dz[j]*z);
		}
	}
	
	ll l = 0, r = INF;
	while( l < r ) {
		ll m = (l + r) >> 1;
		if( check(m) ) r = m;
		else l = m + 1;
	}
	check(r); printf("%lld %lld %lld\n", ansx, ansy, ansz);
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) solve();
}