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
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define read(FILENAME) assert(freopen((FILENAME + ".in").c_str(), "r", stdin))
#define write(FILENAME) assert(freopen((FILENAME + ".out").c_str(), "w", stdout))
#define files(FILENAME) read(FILENAME), write(FILENAME)
using namespace std;
template <typename A, typename B> void chkmin(A &x, B y) {if (x > y) x = y;}
template <typename A, typename B> void chkmax(A &x, B y) {if (x < y) x = y;}
     
typedef pair <int, int> point;
     
const string FILENAME = "input";
const int MAXN = 4e5, p = 1e9 + 7;

bool check(int A, int B) {
    if (A == -1 || B == -1) return false;
    cout << 1 << ' ' << A << ' ' << B << endl;
    string res;
    cin >> res;
    return res == "TAK";
}

int get(int L, int R) {
    if (R == 0) return -1;
    while (R - L > 1) {
        int M = (L + R + 1) >> 1;
        if (check(M, M + 1)) {
            R = M;
        } else {
            L = M;
        }
    } 
    return R;
}

int n, k;

int main() {
    ios::sync_with_stdio(0);
    //read(FILENAME);
    cin >> n >> k;
    int X = get(0, n);
    int Y = get(0, X - 1);
    if (!check(Y, X)) 
        Y = get(X, n);
    cout << 2 << ' ' << X << ' ' << Y << endl;
}