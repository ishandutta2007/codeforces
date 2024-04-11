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

const int p = 1e9 + 7;
const string m = "Bulbasaur";

string s;
vector <int> color;

bool used[26];

int dp[5002][5002];
int cnt[5002][5002];

int sum(int a, int b) {
    a += b;
    if (a >= p)
        a -= p;
    return a;
}

int mul(long long a, int b) {
    return (a * b) % p;
}

int main(int argc, char const *argv[]) {
    srand(time(0));
    int n;
    cin >> n;
    cin >> s;
    for (char i: s) {
        if (color.size() == 0 || color.back() != i - 'a')
            color.pb(i - 'a');
    }
    dp[0][0] = 1;
    for (int i = 0; i < color.size(); ++i) {
        for (int j = 0; j < 26; ++j)
            used[j] = false;
        if (i != 0) used[color[i - 1]] = true;
        for (int j = i; j < color.size(); ++j) {
            if (!used[color[j]]) {
                used[color[j]] = true;
                for (int k = 0; k < color.size(); ++k) 
                    dp[j + 1][k + 1] = sum(dp[j + 1][k + 1], dp[i][k]);
            }
        }
    }
    cnt[1][1] = 1;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= s.size(); ++j) {
            cnt[i + 1][j + 1] = sum(cnt[i + 1][j + 1], cnt[i][j]);
            cnt[i][j + 1] = sum(cnt[i][j + 1], cnt[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= color.size(); ++i) {
        for (int j = 0; j <= color.size(); ++j) {
            if (dp[i][j]) {
                ans = sum(ans, mul(cnt[j][s.size()], dp[i][j]));
            }
        }
    }
    cout << ans << endl;
}