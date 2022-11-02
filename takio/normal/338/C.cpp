#include <stdio.h>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std ;

int n;
LL a[10], b[10];
int res, fa[10], c[10];
map <LL, int> mp;
vector <int> g[10];

int getf (LL x) {
//    cout << x << endl;
    LL t = x;
    if (mp.find (x) != mp.end()) return mp[x];
    if (x == 1) return mp[x] = 0;
    int cnt = 0;
    for (LL i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
    }
    if (x != 1) cnt++;
    return mp[t] = cnt;
}


void dfs (int k) {
//    cout << k << endl;
    if (k == n + 1) {
        for (int i = 1; i <= n; i++) b[i] = a[i];
        int tmp = n;
        memset (c, 0, sizeof c);
        for (int i = 1; i <= n; i++) if (fa[i]) {
            c[fa[i]]++;
            if (b[fa[i]] % a[i] == 0) b[fa[i]] /= a[i];
            else return;
        } else c[0]++;
        tmp += (c[0] > 1);
        for (int i = 1; i <= n; i++) {
            tmp += getf (b[i]);
            if (!c[i] && mp[b[i]] == 1) tmp--;
        }
        if (tmp < res) {
            res = tmp;
//            cout << res << endl;
            for (int i = 1; i <= n; i++) {
//                cout << i << ' ' << fa[i] << ' ' << b[i] << ' ' << getf (b[i]); cout << endl;
            }
        }
        return;
    }
    for (int i = 0; i < (int)g[k].size(); i++) {
        fa[k] = g[k][i];
        dfs (k + 1);
    }
}

int main () {
//    cout << getf (6) << endl;
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        g[i].push_back (0);
        for (int j = 1; j <= n; j++) if (i != j) {
            if (a[i] % a[j] == 0) {
                g[j].push_back (i);
            }
        }
    }
    res = 1e9;
    dfs (1);
//    cout << getf (6) << endl;
    cout << res << endl;
}