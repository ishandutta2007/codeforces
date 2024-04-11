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

int n;

int q = 0;
int ans[20];

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n;
	cout << "? ";
	for (int i = 0; i < n; ++i) cout << '0';
	cout << endl;
	cin >> ans[q++];
	cout << "? ";
	for (int i = 0; i < n; ++i) cout << (i == 0);
	cout << endl;
	cin >> ans[q++];
	int L = 1, R = n - 1;
	if (ans[0] < ans[1]) {
		while (R != L) {
			int M = (L + R) >> 1;
			cout << "? ";
			for (int i = 0; i < n; ++i) {
				cout << (L <= i && i <= M);
			}
			cout << endl;
			cin >> ans[q++];
			if (ans[q - 1] - ans[0] != (M - L + 1)) {
				R = M;
			} else {
				L = M + 1;
			}
		}
		cout << "! " << 1 << ' ' << L + 1 << endl;	
	} else {
		while (R != L) {
			int M = (L + R) >> 1;
			cout << "? ";
			for (int i = 0; i < n; ++i) {
				cout << (L <= i && i <= M);
			}
			cout << endl;
			cin >> ans[q++];
			if (ans[0] - ans[q - 1] != (M - L + 1)) {
				R = M;
			} else {
				L = M + 1;
			}
		}
		cout << "! " << L + 1 << ' ' << 1 << endl;	
	}
}