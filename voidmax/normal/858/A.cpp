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
#include <random>  
#include <ctime>
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 1e6 + 1;

long long a;
int k;

long long gcd(long long a, long long b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	cin >> a >> k;
	cout << (long long)(a * pow(10, k) / gcd(a, pow(10, k)));
}