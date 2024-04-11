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

vector<long long> ans;
int w, h, n;
set<int> vx, vy;
char c[N];
int x[N];

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d %d %d\n", &w, &h, &n);
    vx.insert(0);
    vx.insert(h);
    vy.insert(0);
    vy.insert(w);
    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &c[i], &x[i]);
        if (c[i] == 'H') {
            vx.insert(x[i]);
        } else {
            vy.insert(x[i]);
        }
    }
    int mx = 1;
    int my = 1;
    int last = 0;
    for (auto it = vx.begin(); it != vx.end(); it++) {
        mx = max(mx, *it - last);
        last = *it;
    }
    last = 0;
    for (auto it = vy.begin(); it != vy.end(); it++) {
        my = max(my, *it - last);
        last = *it;
    }
    ans.push_back(mx * 1LL * my);
    for (int i = n - 1; i >= 0; i--) {
        set<int>::iterator it;
        if (c[i] == 'H') {
            it = vx.find(x[i]);
        } else {
            it = vy.find(x[i]);
        }
        auto pit = it;
        auto nit = it;
        pit--;
        nit++;
        if (c[i] == 'H') {
            mx = max(mx, *nit - *pit);
        } else {
            my = max(my, *nit - *pit);
        }
        ans.push_back(mx * 1LL * my);
        if (c[i] == 'H') {
            vx.erase(it);
        } else {
            vy.erase(it);
        }
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) printf("%I64d\n", ans[i]);
}