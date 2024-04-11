#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int a[200200];
int cnt[200200];
int s[200200];

vector <int> v;
bool cmp (int x, int y) {return x > y; }

int main () {
    int T = read();
    while (T--) {
        int n = read(); v.clear();
        int i, j;
        for (i = 1; i <= n; i++) v.push_back(read()), cnt[i] = 0;
        sort(v.begin(), v.end(), cmp);
        n = 0;
        while (!v.empty()) {
            a[++n] = v.back();
            while (!v.empty() && a[n] == v.back()) cnt[n]++, v.pop_back();
        }
        for (i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + cnt[i];
        int now = 0, lef = 1;
        for (i = 1; i <= n; i++) {
            if (cnt[i] - cnt[now] - 1 + lef >= a[i]) lef += cnt[i] - cnt[now], now = i;
        }
        cout << lef << endl;
    }
    return 0;
}