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

int sa[N], n;

void add(int x, int val) {
    for (int i = x; i <= n; i = (i | (i - 1)) + 1) sa[i] += val;
}

int fsum(int x) {
    int res = 0;
    for (int i = x; i; i &= (i - 1)) res += sa[i];
    return res;
}

int getk(int k) {
    int l = 0, r = n;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (fsum(mid) >= k) r = mid; else l = mid;
    }
    return r;
}

vector<int> perm(vector<int> a) {
    vector<int> res(a.size(), 0);
    memset(sa, 0, sizeof(sa));
    for (int i = 0; i < a.size(); i++) {
        res[i] = a[i] - fsum(a[i]);
        add(a[i] + 1, 1);
    }
    return res;
}

vector<int> get(vector<int> a) {
    vector<int> res(a.size(), 0);
    memset(sa, 0, sizeof(sa));
    for (int i = 1; i <= a.size(); i++) add(i, 1);
    for (int i = 0; i < a.size(); i++) {
        res[i] = getk(a[i] + 1);
        add(res[i], -1);
    }
    for (int i = 0; i < res.size(); i++) --res[i];
    return res;
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<int> u = perm(a);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<int> v = perm(a);
    for (int i = n - 1; i >= 0; i--) {
        u[i] += v[i];
        int l = n - i;
        if (i > 0) u[i - 1] += u[i] / l;
        u[i] %= l;
    }
    u = get(u);
    for (int i = 0; i < u.size(); i++) printf("%d ", u[i]);
    puts("");
}