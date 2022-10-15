#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll a, b, c, x1, y1, x2, y2;
	cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
	ld ans=abs(x2-x1)+abs(y2-y1);
	if(a&&b) {
		auto f=[&](ll a, ll b, ll x1, ll y1, ll x2, ll y2) {
			ld ay=(ld)(-c-a*x1)/b, bx=(ld)(-c-b*y2)/a, by=(ld)(-c-a*x2)/b;
			ans=min({abs(y1-ay)+abs(x2-bx)+hypot(x1-bx, y2-ay), abs(y1-ay)+abs(y2-by)+hypot(x2-x1, ay-by), ans});
		};
		f(a, b, x1, y1, x2, y2);
		f(b, a, y1, x1, y2, x2);
	}
	cout << fixed << setprecision(9) << ans;
}