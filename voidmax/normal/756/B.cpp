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
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }


const string FILENAME = "input";

int n;
const int t[3] = {0, 90, 1440};
const int p[3] = {20, 50, 120};

vector <int> arr;

int dp[100002];
int cnt = 0;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    //read(FILENAME);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[i + 1] = 2e6 + 1; 
    }
    int R1 = 0, R2 = 0;
    for (int i = 0; i < n; ++i) {
        while (R1 < n && arr[R1] < arr[i] + t[1]) {
            ++R1;
        }
        while (R2 < n && arr[R2] < arr[i] + t[2]) {
            ++R2;
        }
        if (dp[R1] > dp[i] + p[1]) {
            dp[R1] = dp[i] + p[1];
        }
        if (dp[R2] > dp[i] + p[2]) {
            dp[R2] = dp[i] + p[2];
        }
        if (dp[i + 1] > dp[i] + p[0]) {
            dp[i + 1] = dp[i] + p[0];
        }
    }
    for (int i = n; i > 0; --i) {
        chkmin(dp[i - 1], dp[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << dp[i + 1] - cnt << endl;
        cnt = dp[i + 1];
    }
}