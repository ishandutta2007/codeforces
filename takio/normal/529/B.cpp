#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#define LL long long
#define UN unsigned short
#define ULL unsigned long long
#define pii pair <int, int>
#define piii pair <pii, int>
#define xx first
#define yy second
using namespace std;

const int N = 1010;
int x[N], y[N], t[N];

bool cmp (int a, int b) {
    return a > b;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
    }
    int res = 1e9;
    for (int h = 1; h <= 1000; h++) {
        int ed = n / 2, sum = 0, tn = 0, flag = 0;
        for (int i = 1; i <= n; i++) {
            if (x[i] > h && y[i] > h) { flag = 1; break;}
            if (x[i] > h) sum += x[i];
            else if (y[i] > h) sum += y[i], ed--;
            else {
                sum += x[i];
                if (x[i] > y[i]) t[++tn] = x[i] - y[i];
            }
        }
        if (flag || ed < 0) continue;
        sort (t + 1, t + 1 + tn, cmp);
        for (int i = 1; i <= tn && i <= ed; i++) {
            sum -= t[i];
        }
//        if (res > sum * h) { cout << h << ' ' << sum << endl; for (int i = 1; i <= tn; i++) cout << t[i] << ' '; cout << endl;}
        res = min (res, sum * h);
    }
    cout << res << endl;
}