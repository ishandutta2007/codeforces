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
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
  
typedef int base;
typedef pair<base, base> point;

const string FILENAME = "input";

const int MAXN = 2e5;

bool can(int B1, int A1, int B2, int A2) {
	if ((B1 & 1) != (B2 & 1)) return false;
	if (B1 > B2) return false;
	if (A1 < A2) return false;
	if (B1 == 0 && B2 != 0) {
		if (A1 == 0) return false;
		B1 += 2;
		--A1;
		if (A1 < A2) return false;
		A1 = A2 = 0;
	}
	if ((A1 % 3) == (A2 % 3)) return true;
	if (A1 != 0) {
		B1 += 2;
		A1 = A2 = 0;
	}
	if (A1 != A2) return false;
	if (B1 > B2) return false;
	return true;
}

int m;
string s1, s2;
int A1[MAXN], B1[MAXN], A2[MAXN], B2[MAXN];

pair<int, int> get1(int L, int R) {
	int len = R - L + 1;
	if (A1[R] >= len) return {0, len};
	return {B1[R] - B1[L - 1], A1[R]};
}

pair<int, int> get2(int L, int R) {
	int len = R - L + 1;
	if (A2[R] >= len) return {0, len};
	return {B2[R] - B2[L - 1], A2[R]};
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> s1 >> s2;
	int A = 0, B = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] == 'C') s1[i] = 'B';
		if (s1[i] == 'A') {
			++A;
		} else {
			A = 0;
			++B;
		}
		A1[i + 1] = A;
		B1[i + 1] = B;
	}
	A = 0, B = 0;
	for (int i = 0; i < s2.size(); ++i) {
		if (s2[i] == 'C') s2[i] = 'B';
		if (s2[i] == 'A') {
			++A;
		} else {
			A = 0;
			++B;
		}
		A2[i + 1] = A;
		B2[i + 1] = B;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int L1, R1, L2, R2;
		cin >> L1 >> R1 >> L2 >> R2;
		auto v1 = get1(L1, R1), v2 = get2(L2, R2);
		//cout << v1.x << ' ' << v1.y << endl;
		cout << can(v1.x, v1.y, v2.x, v2.y);
	}
	cout << '\n';
}


//