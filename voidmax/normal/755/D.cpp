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
     
const string FILENAME = "subrev";
const int MAXN = 1e6;

struct fen {
    int ver;
    int used[MAXN];
    int arr[MAXN];
    fen() {
        ver = 1;
    }
    void add(int i) {
        while (i < MAXN) {
            if (used[i] != ver) {
                used[i] = ver;
                arr[i] = 0;
            }
            arr[i]++;
            i = i | (i + 1);
        }
    }
    int get(int i) {
        int sum = 0;
        while (i >= 0) {
            if (used[i] != ver) {
                used[i] = ver;
                arr[i] = 0;
            }
            sum += arr[i];
            i = (i & (i + 1)) - 1;
        }
        return sum;
    }
    int sum(int L, int R) {
        if (R < L) return 0;
        return get(R) - get(L - 1);
    }
};

fen box;

int n, k;

long long cnt = 1;

int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin >> n >> k;
    k = min(k, n - k);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        int L = (j + 1) % n, R = (j + k - 1) % n;
        if (L <= R) {
            cnt += box.sum(L, R) + 1;
        } else {
            cnt += box.sum(L, n - 1) + box.sum(0, R % n) + 1;
        }
        box.add(j);
        j = (j + k) % n;
        box.add(j);
        cout << cnt << ' ';
    }
}