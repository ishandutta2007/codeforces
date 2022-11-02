#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()


using namespace std;

int brute(int n, vector< pair<int, int> > v) {
    vector< vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < (int)v.size(); i++) a[v[i].fr][v[i].sc] = 1;
    vector< vector<int> > can(n, vector<int>(n));
    can[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) continue;
            if ((i > 0) && (can[i - 1][j])) can[i][j] = 1;
            if ((j > 0) && (can[i][j - 1])) can[i][j] = 1;
        }
    }
    return can[n - 1][n - 1] ? 2 * n - 2 : -1;
}

int solve(int n, vector< pair<int, int> > v) {
    if (!v.size()) return 2 * n - 2;
    sort(v.begin(), v.end());
    vector< pair<int, int> > cur;
    cur.pb(mp(0, 1));
    for (int i = 0; (i < (int)v.size()) && (!cur.empty()); ) {
        if (((i == 0) && (v[i].fr != 0)) || ((i > 0) && (v[i].fr > v[i - 1].fr + 1))) {
            cur[0].sc = n;
            cur.resize(1);
        }
        int j = i, k = 0;
        vector< pair<int, int> > ncur;
        while ((i < (int)v.size()) && (v[i].fr == v[j].fr)) {
            int x = v[i].sc;
            int ll;
            if (k < (int)cur.size()) ll = cur[k].fr;
            while ((k + 1 < (int)cur.size()) && (cur[k + 1].fr <= x)) ++k;
            // cerr << x << " " << k << " ";
            // db2(cur[k].fr, cur[k].sc);
            if ((k < (int)cur.size()) && (cur[k].fr <= x)) {
                if (ll < x) ncur.pb(mp(ll, x));
                while ((k < (int)cur.size()) && (cur[k].sc <= x + 1)) ++k;
                if (k < (int)cur.size()) cur[k].fr = max(cur[k].fr, x + 1);
            }
            ++i;
        }
        if (k < (int)cur.size()) ncur.pb(mp(cur[k].fr, n));
        if (v[i - 1].fr == 0) { cur[0].sc = v[0].sc; continue; }
        cur = ncur;
        // for (int j = 0; j < (int)cur.size(); j++) db2(cur[j].fr, cur[j].sc);
        // cerr << "---------------------" << endl;
    }
    if ((!cur.empty()) && ((v.back().fr != n - 1) || (cur.back().sc == n))) {
        return 2 * n - 2;
    } else {
        return -1;
    }   
}

void stress() {
    for (int it = 0; ; it++) {
        cerr << it << ": ";
        int n = rand() % 30 + 1;
        int m = rand() % (5 * n);
        vector< pair<int, int> > v;
        for (int i = 0; i < m; i++) {
            int x = rand() % n;
            int y = rand() % n;
            if (x + y == 0) continue;
            v.pb(mp(x, y));
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        cerr << v.size() << endl;
        cerr << n << " ";
        int ans1 = brute(n, v);
        int ans2 = solve(n, v);
        if (ans1 == ans2) {
            cerr << "ok!" << endl;
        } else {
            cerr << n << endl;
            vector< vector<int> > mark(n, vector<int>(n));
            for (int i = 0; i < (int)v.size(); i++) mark[v[i].fr][v[i].sc] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!mark[i][j]) cerr << "."; else cerr << "*";
                }
                cerr << endl;
            }
            // cerr << n << " ";
            // for (int i = 0; i < (int)v.size(); i++) cerr << "(" << v[i].fr << ", " << v[i].sc << ") ";
            //  cerr << endl;
            assert(false);
        }
    }
}

int main() {
    // stress();
    // freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    vector< pair<int, int> > v;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        v.pb(mp(x, y));
    }
    cout << solve(n, v) << endl;
}