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
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }


const string FILENAME = "input";
typedef pair<int, int> point;
typedef long double base;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
set<int> bad[100001];
vector<int> clr[2];
vector<int> res;
vector<int> arr;

vector<int> ans[100001];

int get_id(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m)
		return -1e9;
	return i * m + j;
}

bool check(int i, int j, int clr) {
	for (int d = 0; d < 4; ++d) {
		int X = i + dx[d], Y = j + dy[d];
		if (!(X < 0 || X >= n || Y < 0 || Y >= m)) {
			if (bad[clr].count(ans[X][Y])) {
				return false;
			}
		}
	}
	return true;
}

void get_nxt(int &X, int &Y) {
	++Y;
	if (Y == m) {
		++X;
		Y = 0;
	}
}

int main() {
	srand(time(0));
   	ios::sync_with_stdio(0);
   	//read(FILENAME);
   	cin >> n >> m;
   	for (int i = 0; i < (n * m); ++i) {
   		int X = i / m, Y = i % m;
   		for (int d = 0; d < 4; ++d) {
   			//if (get_id(X + dx[d], Y + dy[d]) >= 0) cout << i + 1 << ' ' << get_id(X + dx[d], Y + dy[d]) + 1 << endl;
   			bad[i].insert(get_id(X + dx[d], Y + dy[d]));
   		}
   		clr[(X + Y) & 1].pb(i);
   	}
   	for (int s = 0; s < 2; ++s) {
   		for (int i = 0; i < n; ++i) {
   			ans[i].resize(m);
   		}
   		for (int t = 0; t < 5; ++t) {
	   		for (int i = 0; i < n; ++i) {
	   			for (int j = 0; j < m; ++j) {
	   				ans[i][j] = -1;
	   			}
	   		}
	   		res = clr[1];
	   		random_shuffle(clr[0].begin(), clr[0].end());
	   		random_shuffle(res.begin(), res.end());
	   		int X = 0, Y = 0;
	   		for (int c : clr[0]) {
	   			ans[X][Y] = c;
	   			get_nxt(X, Y);
	   		}
	   		bool OK = true;
	   		for (int j = 0; j < clr[1].size(); ++j) {
	   			bool found = false;
	   			for (int q = 0; q < res.size(); ++q) {
	   				if (check(X, Y, res[q])) {
	   					ans[X][Y] = res[q];
	   					found = true;
	   					swap(res.back(), res[q]);
	   					res.pop_back();
	   					break;
	   				}
	   			}
	   			if (!found) {
	   				OK = false;
	   				break;
	   			}
	   			get_nxt(X, Y);
	   		}
	   		if (OK) {
	   			cout << "YES\n";
	   			if (s) {
	   				for (int i = 0; i < m; ++i) {
	   					for (int j = 0; j < n; ++j) {
	   						cout << ans[j][i] + 1 << ' ';
	   					}
	   					cout << '\n';
	   				}
	   			} else {
	   				for (int i = 0; i < n; ++i) {
	   					for (int j = 0; j < m; ++j) {
	   						cout << ans[i][j] + 1 << ' ';
	   					}
	   					cout << '\n';
	   				}
	   			}
	   			return 0;
	   		}
	   	}
   		swap(n, m);
   	}
   	cout << "NO" << endl;
}