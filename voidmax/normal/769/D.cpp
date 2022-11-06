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

const string FileName = "input";

const int MAXN = 2e4;

int n, k;
int len[MAXN];
vector <int> mask;
int cnt[MAXN];
long long ans;

int main(int argc, char const *argv[]) {
    srand(time(0));
    //read(FileName);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    len[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        len[i] = len[i / 2] + (i % 2); 
    }
    for (int i = 0; i < MAXN; ++i) {
        if (len[i] == k) mask.pb(i);
    }
    if (k != 0) {
        for (int i = 0; i <= 1e4; ++i) {
            for (int j: mask) {
                if ((i ^ j) < MAXN) {
                    ans += (long long)cnt[i ^ j] * cnt[i];
                }
            }
        }
    } else {
        for (int i = 0; i <= 1e4; ++i) {
            ans += (long long)cnt[i] * (cnt[i] - 1);
        }
    }
    cout << ans / 2 << endl;
}