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
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

typedef long long base;

const string FILENAME = "input";

int n;

long long sum = 0;
int ans[5001];
int arr[5001];
int main() {
	//read(FILENAME);
	ios::sync_with_stdio(false);
	cin >> n;
	For(i, 0, n - 1) {
		cout << "?" << ' ' << 1 << ' ' << i + 2 << endl;
		cin >> ans[i];
	}
	cout << '?' << ' ' << 2 << ' ' << 3 << endl;
	cin >> ans[n - 1];
	arr[0] = ans[0] + ans[1] - ans[n - 1];
	arr[0] /= 2;
	cout << "!" << ' ' << arr[0] << ' ';
	For(i, 0, n - 1) {
		cout << ans[i] - arr[0] << ' ';
	}
	cout << endl;
	long long res;
}