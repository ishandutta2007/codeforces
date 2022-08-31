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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef ll Num;

const ll B = (ll)1e9;
//const ll B = 10;
struct Num {
	vector<ll> a;

	Num () : a() {}
	Num(ll x) {
		a.clear();
		while(x > 0) {
			a.push_back(x % B);
			x /= B;
		}
	}

	Num operator + (const Num &A) const {
		Num R = Num();
		ll d = 0;
		for (int i = 0; i < (int)a.size() || i < (int)A.a.size() || d; i++) {
			if (i < (int)a.size()) d += a[i];
			if (i < (int)A.a.size()) d += A.a[i];
			R.a.push_back(d % B);
			d /= B;
		}
		return R;
	}

	void print() const {
		if (a.empty()) {
			printf("0\n");
			return;
		}
		printf("%lld", a.back());
		for (int i = (int)a.size() - 2; i >= 0; i--)
			printf("%09lld", a[i]);
		printf("\n");
	}
};

const int N = 600100;
int s[N];
int pi[N];
vector<int> needToErase[N];
int st[N][2];
int stSz;
ll globMin;
Num TOT = 0;
ll TOTm30 = 0;
ll TOTm26;
ll CUR = 0;
int n;
int fenv[N];
set<int> setik;

void addFenv(int p, int x) {
	for(; p < N; p |= p + 1)
		fenv[p] += x;
}
int getFenv(int r) {
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}

int getCost(int v) {
	int l = 0, r = stSz;
	while(r - l > 1) {
		int mid = (l + r) / 2;
		if (st[mid][0] > v)
			r = mid;
		else
			l = mid;
	}
	return st[l][1];
}
void turnOff(int v) {
	CUR -= getCost(v);
	addFenv(v, -1);
	setik.erase(v);
}
void turnOn(int v) {
	CUR += getCost(v);
	addFenv(v, 1);
	setik.insert(v);
}

void solve(int p, int w) {
	eprintf("solve %d %d %d\n", p, w, s[p]);
	int l = p;
	while(stSz > 0 && st[stSz - 1][1] >= w) {
		stSz--;
		CUR -= (ll)(getFenv(l - 1) - getFenv(st[stSz][0] - 1)) * st[stSz][1];
		l = st[stSz][0];
	}
	CUR += (ll)(getFenv(p) - getFenv(l - 1)) * w;
	st[stSz][0] = l;
	st[stSz][1] = w;
	stSz++;

	if (p == 0) {
		globMin = w;
		CUR = w;
		pi[0] = 0;
//		turnOn(0);
		return;
	}

	CUR -= globMin;
	globMin = min(globMin, (ll)w);
	CUR += globMin;
	
	pi[p] = pi[p - 1];
	while(pi[p] > 0 && s[p] != s[pi[p]]) pi[p] = pi[pi[p] - 1];
	if (pi[p] == 0) {
		while(!setik.empty()) {
			int v = *setik.begin();
			needToErase[p].push_back(p - v);
			turnOff(v);
		}
		if (s[p] == s[0]) {
			pi[p] = 1;
			turnOn(p);
		}
		return;
	}

	while(!setik.empty()) {
		int v = *setik.begin();
		if (v >= p - pi[p]) break;
		needToErase[p].push_back(p - v);
		turnOff(v);
	}
	for (int len : needToErase[pi[p]]) {
		needToErase[p].push_back(len);
		turnOff(p - len);
	}
	pi[p]++;
	if (s[p] == s[0]) {
		turnOn(p);
	}
}

void printAns() {
	//printf("%lld\n", TOT);
	TOT.print();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c;
		int w;
		scanf(" %c %d", &c, &w);
		int cc = (int)(c - 'a');
		s[i] = (cc + TOTm26) % 26;
		w ^= TOTm30;
		solve(i, w);
		TOT = TOT + Num(CUR);
		TOTm30 = (TOTm30 + CUR) % (1LL << 30);
		TOTm26 = (TOTm26 + CUR) % 26;
		printAns();
	}

	return 0;
}