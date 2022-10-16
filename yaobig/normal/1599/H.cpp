#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ops = 0;
ll rx0, ry0, rx1, ry1;

ll ask(ll x, ll y) {
	cout << "? " << x << ' ' << y << endl;
	
	ll d;
	cin >> d;
	
	/*
	d = 0;
	if (x < rx0) d += rx0 - x;
	if (x > rx1) d += x - rx1;
	if (y < ry0) d += ry0 - y;
	if (y > ry1) d += y - ry1;
	*/

	++ops;
	assert(d != -1);
	return d;
}

void answer(ll x0, ll y0, ll x1, ll y1) {
	cout << "! " << x0 << ' ' << y0 << ' ' << x1 << ' ' << y1 << endl;
}

const ll H = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// cin >> rx0 >> ry0 >> rx1 >> ry1;

	ll d00 = ask(1, 1);
	ll d10 = ask(H, 1);
	ll d11 = ask(H, H);
	ll d01 = ask(1, H);

	ll max_x = 1 + d00;
	ll min_x = H - d10;
	ll opt_x = (max_x + min_x) / 2;
	// cerr << min_x << ' ' << max_x << '\n';

	ll y0 = ask(opt_x, 1) + 1;
	ll x0 = d00 - y0 + 2;
	ll dy = d01 - x0;
	ll dx = d10 - y0;
	ll y1 = H - dy - 1;
	ll x1 = H - dx - 1;

	answer(x0, y0, x1, y1);
}