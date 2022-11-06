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

const int MAXN = 1e5 + 1;

int a, b, c;

int main() {
	srand(time(0));
   	ios::sync_with_stdio(0);
   	//read(FILENAME);
   	cin >> a >> b >> c;
 	for (int i = 0; i < 10; ++i) {
 		for (int j = 0; j < 10; ++j) {
 			for (int q = 0; q < 10; ++q) {
 				bool OK = true;
 				for (int d = 0; d < 2000; ++d) {
 					if ((d % a) == i || (d % b) == j || (d % c) == q)
 						continue;
 					OK = false;
 					break;
 				}
 				if (OK) {
 					cout << "YES" << endl;
 					return 0;
 				}
 			}
 		}
 	}
 	cout << "NO" << endl;
}