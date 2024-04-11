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

const string FILENAME = "input";
const int MAXH = 20000;
int n, H;



int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(0);
   	//read(FILENAME);   
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	int t;
    	string s;
    	cin >> t >> s;
    	if (s == "West" || s == "East") {
    		if (H == 0 || H == MAXH) {
    			cout << "NO" << endl;
    			return 0;
    		}
    	} else {
    		if (s == "South") {
    			H += t;
    		} else {
    			H -= t;
    		}
    	}
    	if (H < 0 || H > MAXH) {
    		cout << "NO" << endl;
    		return 0;
    	}
    }
    if (H != 0) {
    	cout << "NO" << endl;
    	return 0;
    }
    cout << "YES" << endl;
}