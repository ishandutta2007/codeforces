#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

const int N = 666666;

int u, n, a[N], sa[N], neg, c0, c1;
long long ans = 0;

void init(int l, int r) {
    memset(sa, 0, sizeof(sa));
    neg = 0;
    c0 = 0;
    c1 = 0;
    for (int i = l; i < r; i++) sa[a[i]]++;
    for (int i = 0; i < N; i++) {
        if (sa[i] & 1) c1++; else c0++;
    }
}

void add(int x) {
    int y = a[x];
    if (sa[y] < 0) neg--; 
    if (sa[y] & 1) c1--; else c0--;
    if (x < n / 2) sa[y] -= 2; else
    if (x * 2 == (n - 1)) sa[y]--; else {
        if (a[x] != a[n - x - 1]) neg++;
    }
    if (sa[y] < 0) neg++;
    if (sa[y] & 1) c1++; else c0++;
}

bool can() {
    if (neg > 0) return false;
    if (c1 > 1) return false;
    return true;
}

void print() {
    printf("%d %d %d\n", neg, c0, c1);
}

void solve() {
//  cerr << "--" << endl;
    init(u, n - u);
    for (int i = u; i < n - u - 1; i++) {
        add(i);
//      print();
        if (can()) ans += u + 1;
    }
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bool pal = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[n - i - 1]) {
            pal = false;
            u = i;
            break;
        }
    }
    if (pal) {
        cout << n * 1LL * (n + 1) / 2 << endl;
        return 0;
    }
    solve();
    reverse(a, a + n);
    solve();
    init(0, n);
    if (can()) ans += (u + 1) * 1LL * (u + 1);
    cout << ans << endl;
}