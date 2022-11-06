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
#define less less228
#define more more228
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
const int MAXH = 20000;

int n;
int more = -1e9, less = 1e9;

int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(0);
   	//read(FILENAME);   
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	int c, d;
    	cin >> c >> d;
    	if (d == 2) {
    		chkmin(less, 1899);
    	} else {
    		chkmax(more, 1900);
    	}
    	more += c;
    	less += c;
    	if (less < more) {
	    	cout << "Impossible" << endl;
	    	return 0;
	    }
    }
    if (less > 1e8) {
    	cout << "Infinity" << endl;
    } else {
    	cout << less << endl;
    }
}