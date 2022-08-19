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
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 100100;
string a[N];
int n;

bool solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	set<string> R;
	for (int i = 0; i < n; i++) {
		string s = a[i];
		reverse(all(s));
		if (s == a[i]) return true;
		R.insert(s);
	}
	for (int i = 0; i < n; i++) {
		if (R.find(a[i]) != R.end()) return true;
	}
	R.clear();
	for (int i = 0; i < n; i++) {
		if ((int)a[i].length() == 2) {
			string s = a[i];
			reverse(all(s));
			R.insert(s);
		} else {
			if (R.find(a[i].substr(1, 3)) != R.end()) return true;
		}
	}
	R.clear();
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
		reverse(all(a[i]));
	for (int i = 0; i < n; i++) {
		if ((int)a[i].length() == 2) {
			string s = a[i];
			reverse(all(s));
			R.insert(s);
		} else {
			if (R.find(a[i].substr(1, 3)) != R.end()) return true;
		}
	}
	
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}