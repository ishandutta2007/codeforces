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
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 1e6 + 1;

int n, k;

vector <pair <int, int>> elem;

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n >> k;
	elem.pb({n, 0});
	for (int i = 0; i < 19; ++i) {
		vector <pair <int, int>> new_elem;
		int cnt = 0, id = (int)elem.size() - 1;
		for (int j = 0; j < elem.size(); ++j) {
			if (elem[j].x & 1) {
				id = j;
				break;
			}
		}
		for (int j = 0; j < elem.size(); ++j) {
			if (j == id) continue;
			cnt += elem[j].x / 2;
		}
		cnt = cnt + (elem[id].x / 2);
		if ((cnt & 1) == (k & 1)) {
			for (int j = 0; j < elem.size(); ++j) {
				if (elem[j].x / 2) new_elem.pb({elem[j].x / 2, elem[j].y + (1 << i)});
				new_elem.pb({(elem[j].x + 1) / 2, elem[j].y});
			}
		} else {
			for (int j = 0; j < elem.size(); ++j) {
				if (j == id) {
					new_elem.pb({(elem[j].x) / 2 + 1, elem[j].y + (1 << i)});
					if (elem[j].x - ((elem[j].x) / 2 + 1)) new_elem.pb({elem[j].x - ((elem[j].x) / 2 + 1), elem[j].y});
				} else {
					if (elem[j].x / 2) new_elem.pb({elem[j].x / 2, elem[j].y + (1 << i)});
					new_elem.pb({(elem[j].x + 1) / 2, elem[j].y});
				}
			}
		}
		swap(new_elem, elem);
		sort(elem.begin(), elem.end());
		k >>= 1;
	}
	if (elem.size() == n) {
		cout << "YES" << '\n';
		int cnt = 0;
		for (auto i : elem) {
			cnt ^= i.y;
			cout << i.y << ' ';
		}
		cout << '\n';
	} else {
		cout << "NO" << '\n';
	}
}