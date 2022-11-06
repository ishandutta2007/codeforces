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

string arr[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int n;
map <string, int> num;

int sum[6];

string s;

int ans[100001];

vector <pair <int, int>> res;

int main() {
	//read(FILENAME);
	ios::sync_with_stdio(false);
	For(i, 0, 6) {
		num[arr[i]] = i;
		cin >> sum[i];
	}
	cin >> n;
	For(i, 0, n) {
		cin >> s;
		if (num.count(s)) {
			--sum[num[s]];
			ans[i] = num[s];
		} else {
			while (true) {
				if (s.back() == ',') {
					s.pop_back();
					break;
				} else {
					s.pop_back();
				}
			}
			res.pb({num[s], i});
		}
	}
	sort(res.begin(), res.end());
	for (auto i: res) {
		if (sum[i.x] <= 0) {
			--sum[i.x + 1];
			ans[i.y] = i.x + 1;
		} else {
			--sum[i.x];
			ans[i.y] = i.x;
		}
	}
	For(i, 0, 6) {
		if (sum[i] < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	For(i, 0, n) {
		cout << arr[ans[i]] << endl;
	}
}