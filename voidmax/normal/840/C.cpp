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
typedef long long base;


const string FILENAME = "input";
const int MAXN = 400, p = 1e9 + 7, END = 3e5;

int sum(int a, int b) {
    a += b;
    if (a >= p)
        return a - p;
    return a;
}

int mul(long long a, int b) {
    return (a * b) % p;
}

int ans, n, m;
int f[MAXN][MAXN];
int cnk[MAXN][MAXN];
int dp[MAXN][MAXN];
vector <int> arr;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    //cin >> n;
    f[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            f[i][j] = sum(mul(i, f[i - 1][j - 1]), mul(i + j - 1, f[i][j - 1]));
        }
    }
    cnk[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        cnk[i][0] = cnk[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            cnk[i][j] = sum(cnk[i - 1][j], cnk[i - 1][j - 1]);
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; ++j) {
            while (a % (j * j) == 0) {
                a /= j * j;
            }
        }
        arr.pb(a);
    }
    sort(arr.begin(), arr.end());
    dp[0][0] = 1;
    int L = 0, R = 0;
    while (L < n) {
        while (R < n && arr[L] == arr[R]) {
            ++R;
        }
        if (L == 0) {
            dp[R][R - 1] = f[1][R];
        } else {
            for (int j = 1; j <= R - L; ++j) {
                for (int b = 0; b < L; ++b) {
                    for (int c = 0; c <= b && c <= j; ++c) {
                        int Lb = c, Rb = j - c;
                        int Lk = b, Rk = L - b + 1;
                        int nb = b - c + (R - L - j);
                        //cout << Lk << ' ' << Lb << ' ' << Rk << ' ' << Rb << ' ' << Lb + Rb << ' ' << R - L << endl;
                        //if (cnk[Lk][Lb] == 0 || cnk[Rk][Rb] == 0 || f[Lb + Rb][R - L] == 0 || dp[L][b] == 0) continue;
                        //cout << L << ' ' << b << ' ' << c << ' ' << R - L << endl;
                        //cout << dp[R][nb] << ' ';
                        dp[R][nb] = sum(dp[R][nb], mul(dp[L][b], mul(cnk[Lk][Lb], mul(cnk[Rk][Rb], f[Lb + Rb][R - L]))));
                        //cout << dp[R][nb] << ' ' << Lb + Rb << ' ' << R - L << ' ' << f[Lb + Rb][R - L] << endl;
                    }
                }
            }
        } 
        //cout << R - L << ' ' << dp[R][0] << endl;  
        L = R;
    }
    cout << dp[n][0] << endl;
}