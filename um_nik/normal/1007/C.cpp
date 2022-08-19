#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

const ll B = (ll)1e9;
const int SZ = 5;

//typedef long long Num;

struct Num {
	ll a[SZ];

	Num() : a() {}
	Num(ll x) {
		for (int i = 0; i < SZ; i++) {
			a[i] = x % B;
			x /= B;
		}
	}

	Num operator + (const Num &A) const {
		Num R = Num();
		ll d = 0;
		for (int i = 0; i < SZ; i++) {
			d += a[i] + A.a[i];
			R.a[i] = d % B;
			d /= B;
		}
		return R;
	}
	Num operator * (const Num &A) const {
		Num R = Num();
		for (int i = 0; i < SZ; i++)
			for (int j = 0; i + j < SZ; j++)
				R.a[i + j] += a[i] * A.a[j];
		for (int i = 0; i < SZ - 1; i++) {
			R.a[i + 1] += R.a[i] /B;
			R.a[i] %= B;
		}
		return R;
	}
	Num operator / (const ll &x) const {
		Num R = Num();
		ll d = 0;
		for (int i = SZ - 1; i >= 0; i--) {
			d = d * B + a[i];
			R.a[i] = d / x;
			d %= x;
		}
		return R;
	}
	bool operator < (const Num &A) const {
		for (int i = SZ - 1; i >= 0; i--) {
			if (a[i] != A.a[i])
				return a[i] < A.a[i];
		}
		return false;
	}
};

vector<pll> a;
ll N;
ll U, R;

Num getSX(ll X) {
	Num S = Num();
	for (int i = 1; i < (int)a.size(); i++) {
		if (a[i].first <= X) continue;
		S = S + Num(a[i].first - max(a[i - 1].first, X)) * Num(U - a[i].second);
	}
	return S;
}
Num getSY(ll Y) {
	Num S = Num();
	for (int i = (int)a.size() - 2; i >= 0; i--) {
		if (a[i].second <= Y) continue;
		S = S + Num(a[i].second - max(a[i + 1].second, Y)) * Num(R - a[i].first);
	}
	return S;
}

ll getX() {
	Num S = getSX(0) / 3LL;
	ll l = 0, r = R;
	while(r - l > 1) {
		ll x = (l + r) / 2;
		if (S < getSX(x))
			l = x;
		else
			r = x;
	}
	return r;
}
ll getY() {
	Num S = getSY(0) / 3LL;
	ll l = 0, r = U;
	while(r - l > 1) {
		ll y = (l + r) / 2;
		if (S < getSY(y))
			l = y;
		else
			r = y;
	}
	return r;
}

void cutX(ll X) {
	R = X - 1;
	int pos = (int)a.size() - 1;
	while(a[pos - 1].first >= X) pos--;
	a[pos].first = X - 1;
	while((int)a.size() > pos + 1) a.pop_back();
}
void cutY(ll Y) {
	reverse(a.begin(), a.end());
	U = Y - 1;
	int pos = (int)a.size() - 1;
	while(a[pos - 1].second >= Y) pos--;
	a[pos].second = Y - 1;
	while((int)a.size() > pos + 1) a.pop_back();
	reverse(a.begin(), a.end());
}

void cut3(ll X, ll Y) {
	vector<pll> b;
	for (pll t : a) {
		if (t.second > Y) {
			b.push_back(t);
		}
	}
	b.push_back(mp(X, Y));
	for (pll t : a) {
		if (t.first > X) {
			b.push_back(t);
		}
	}
	a = b;
}

bool query() {
	/*
	cerr << "!!! " << R << " " << U << endl;
	for (pll t : a)
		cerr << "(" << t.first << " " << t.second << ") ";
	cerr << endl;
	*/
	ll X = getX();
	ll Y = getY();
	printf("%lld %lld\n", N - X, N - Y);
	fflush(stdout);
	int t;
	scanf("%d", &t);
	if (t == 0) return true;
	if (t == 1)
		cutX(X);
	else if (t == 2)
		cutY(Y);
	else
		cut3(X, Y);
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld", &N);
	R = U = N;
	N++;
	a.push_back(mp(0LL, U));
	a.push_back(mp(R, 0LL));
	while(!query()) {}

	return 0;
}