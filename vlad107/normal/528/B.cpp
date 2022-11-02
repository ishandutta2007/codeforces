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

const int N = 5e5;

int sa[N], x[N], w[N], n;
vector<int> v;

void mod(int x, int val) {
    ++x;
    while (x < N) {
        sa[x] = max(sa[x], val);
        x = (x | (x - 1)) + 1;
    }
}

int fs(int x) {
    ++x;
    int res = 0;
    while (x) {
        res = max(res, sa[x]);
        x &= x - 1;
    }
    return res;
}

bool cmp(int u, int v) {
    return x[u] < x[v];
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    vector<int> nom(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &w[i]);
        v.push_back(x[i] + w[i]);
        v.push_back(x[i] - w[i]);
        nom[i] = i;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    sort(nom.begin(), nom.end(), cmp);
    for (int it = 0; it < n; it++) {
        int i = nom[it];
        int ll = lower_bound(v.begin(), v.end(), x[i] - w[i]) - v.begin();
        int rr = lower_bound(v.begin(), v.end(), x[i] + w[i]) - v.begin();
        mod(rr, fs(ll) + 1);
    }
    printf("%d\n", fs(v.size()));
}