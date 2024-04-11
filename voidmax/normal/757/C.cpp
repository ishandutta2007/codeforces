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

const int p = 1e9 + 7, q = 163941, p1 = 1e9 + 9, q1 = 228227;

const string FILENAME = "input";

int n, m;
int res = 1, res1 = 1;
int hsh[1000001], hsh1[1000001];
map <point, int> cnt;

int sum(int a, int b) {
    a += b;
    if (a >= p)
        a -= p;
    return a;
}

int sum1(int a, int b) {
    a += b;
    if (a >= p1)
        a -= p1;
    return a;
}

int mul(long long a, int b) {
    return (a * b) % p;
}

int mul1(long long a, int b) {
    return (a * b) % p1;
}


int fuctorial[1000001];
int ans = 1;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    //read(FILENAME);
    srand(time(0));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int g;
        cin >> g;
        for (int j = 0; j < g; ++j) {
            int k;
            cin >> k;
            hsh[k - 1] = sum(hsh[k - 1], res);
            hsh1[k - 1] = sum(hsh1[k - 1], res1);
        }
        res = mul(res, q);
        res1 = mul(res1, q1);
    }
    fuctorial[0] = 1;
    for (int i = 1; i <= m; ++i) {
        fuctorial[i] = mul(fuctorial[i - 1], i);
    }
    for (int i = 0; i < m; ++i) {
        cnt[make_pair(hsh[i], hsh1[i])]++;
    }
    for (auto i: cnt) {
        ans = mul(ans, fuctorial[i.y]);
    }
    cout << ans << endl;
}