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

int a, b;

vector <int> arr;

void res(long long a, int b) {
	arr.pb(a);
	if (a == b) {
		cout << "YES" << endl;
		cout << arr.size() << endl;
		for (int i: arr) {
			cout << i << ' ';
		}
		cout << endl;
		exit(0);
	}

	if (a > b) {
		arr.pop_back();
		return;
	}
	res(a * 10 + 1, b);
	res(a * 2, b);
	arr.pop_back();
}

int main() {
	//read(FILENAME);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	res(a, b);
	cout << "NO" << endl;
}