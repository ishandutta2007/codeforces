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
//#include "grader.h"
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
 
typedef long long base;
 
const string FILENAME = "input";
const int MAXN = 1e5 + 1;
const base Pi = acos(-1);
 
long long n, t, k, d;
long long t1 = 0, t2 = 0;

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> n >> t >> k >> d;
    for (int i = 0; i < 10000000; ++i) {
        long long n1 = i / t * k;
        long long n2 = n1;
        if (i >= d) n2 += (i - d) / t * k;
        //cout << n1 << ' ' << n2 << endl;
        if (n1 >= n) {
            cout << "NO" << endl;
            return 0;
        }
        if (n2 >= n) {
            cout << "YES" << endl;
            return 0;
        }
    }
}