// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//#include "grader.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define read(FILENAME) assert(freopen((FILENAME + ".in").c_str(), "r", stdin))
#define write(FILENAME) assert(freopen((FILENAME + ".out").c_str(), "w", stdout))
#define files(FILENAME) read(FILENAME), write(FILENAME)
using namespace std;
template <typename A, typename B> void chkmin(A &x, B y) {if (x > y) x = y;}
template <typename A, typename B> void chkmax(A &x, B y) {if (x < y) x = y;}
     
typedef pair <int, int> point;
     
const string FILENAME = "input";
const int MAXN = 2e5 + 1, p = 1e9 + 7;

int n;
int f[MAXN][2];
long long ans = 0;

int mul(long long a, int b) {
	return (a * b) % p;
}

int sum(long long a, int b) {
	a += b;
	if (a >= p)
		a -= p;
	return a;
}

int powx(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

vector <int> arr, res;

int main() {
	//read(FILENAME);
	cin >> n;
	f[0][0] = f[0][1] = 1;
	for (int i = 1; i < n; ++i) {
		f[i][0] = mul(f[i - 1][0], i);
		f[i][1] = powx(f[i][0], p - 2);
	}
	int m = n;
	while (m % 4 != 1) {
		--m;
	}
	for (int i = 0; i <= m / 2; ++i) {
		if (i) arr.pb(0);
		arr.pb(mul(mul(f[m / 2][0], f[m / 2 - i][1]), f[i][1]));
	}
	while (m != n) {
		res.clear();
		res.pb(0);
		for (int i: arr) 
			res.pb(i);
		arr.pb(0);
		bool OK = 1;
		if (m % 4 == 3) swap(arr, res), OK = 0;
		for (int i = 0; i < arr.size(); ++i) {
			if (OK) {
				arr[i] = sum(arr[i], p - res[i]);
			} else {
 				arr[i] = sum(arr[i], res[i]);
			}
			OK ^= 1;
		}
		++m;
	}	
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ans = sum(ans, mul(a, arr[i]));
	}
	cout << ans << endl;
}