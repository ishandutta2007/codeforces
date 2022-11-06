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
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

int n, m;
int arr1[20][20];

bool check(vector <int> arr) {
	For(i, 0, n) {

		int cnt = 0;
		For(j, 0, m) cnt += (arr1[i][j] - 1) != arr[j];
		if (cnt > 2) return false;
	}
	return true;
}

int main() {
	//read(FILENAME);
	cin >> n >> m;
	For(i, 0, n) For(j, 0, m) cin >> arr1[i][j];
	vector <int> arr;
	For(i, 0, m) {
		arr.pb(i);
	}
	For(i, 0, m) {
		For(j, 0, m) {
			swap(arr[i], arr[j]);
			if (check(arr)) {
				cout << "YES" << endl;
				exit(0);
			}
			sort(arr.begin(), arr.end());
		}
	}
	cout << "NO";
}