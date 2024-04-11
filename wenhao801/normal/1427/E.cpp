#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

using ll = long long;
void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) { x = 1, y = 0; return; }
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
}

vector <pair <pair <ll, ll>, bool>> ans;
void mul(ll a, ll b) {
	ll ret = 0;
	while (b) {
		if (b & 1) {
			if (ret) ans.push_back({{a, ret}, 0});
			ret += a;
		}
		a <<= 1, b >>= 1;
	}
}

int main() {
	ll a; cin >> a;
	int i, j;
	for (i = 20; i >= 0; i--) if ((a >> i) & 1) break;
	for (ll x = a; x <= ll(2.5e18); x <<= 1) ans.push_back({{x, x}, 0});
	ans.push_back({{a << i, a}, 1});
	ll b = (a << i) ^ a, x, y;
	exgcd(a, b, x, y);
	if (x < 0) x = -x; else y = -y;
	if (((x * a) ^ (y * b)) != 1) x += b, y += a;
	for (ll x = b; x <= ll(2.5e18); x <<= 1) ans.push_back({{x, x}, 0});
	mul(a, x), mul(b, y); ans.push_back({{a * x, b * y}, 1});
	printf("%d\n", ans.size());
	for (auto i: ans) printf("%lld %c %lld\n", i.first.first, "+^"[i.second], i.first.second);
	return 0;
}