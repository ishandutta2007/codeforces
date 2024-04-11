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
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

using namespace std;
const long long INF = 1e18;
const string FILENAME = "input";

typedef pair <long long, long long> point;

int n, m[2];
vector <int> arr[2];
queue <int> que[2];
int func[7001][2];
int len[7001][2];

int main() {
	srand(time(0));
	//read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int t = 0; t < 2; ++t) {
		cin >> m[t];
		arr[t].resize(m[t]);
		for (int j = 0; j < m[t]; ++j) {
			cin >> arr[t][j];
		}
		for (int i = 0; i < n; ++i) {
			len[i][t] = m[t];
		}
	}
	func[0][0] = func[0][1] = 2;
	que[0].push(0);
	que[1].push(0);
	while (que[0].size() || que[1].size()) {
		for (int t = 0; t < 2; ++t) {
			if (que[t].size()) {
				int u = que[t].front();
				que[t].pop();
				//cout << u << ' ' << t << endl;
				if (func[u][t] == 1) {
					for (int j: arr[!t]) {
						int v = (u - j + n) % n;
						if (func[v][!t]) continue;
						if (len[v][!t] == 1) {
							//cout << v << ' ' << !t << ' ' << 2 << endl;
							que[!t].push(v);
							func[v][!t] = 2;
						} else {
							--len[v][!t];
						}
					}
				} else {
					for (int j: arr[!t]) {
						int v = (u - j + n) % n;
						if (func[v][!t]) continue;
						que[!t].push(v);
						func[v][!t] = 1;
						//cout << v << ' ' << !t << ' ' << 1 << endl;
					}
				}
			}
		}
	}
	for (int t = 0; t < 2; ++t) {
		for (int i = 1; i < n; ++i) {
			if (func[i][t] == 0) {
				cout << "Loop" << ' '; 
			} else if (func[i][t] == 1) {
				cout << "Win" << ' ';
			} else {
				cout << "Lose" << ' ';
			}
		}
		cout << endl;
	}
}