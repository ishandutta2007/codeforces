#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define x first
#define y second
#define point pair <int, int>
#define dir second
#define mp make_pair
using namespace std;

int n, m, counter;
int w[2], L[2], f[2];
int win;
int arr[100001];
int bin[100001][2];
vector <int> next[2];
vector <point> ans;

int Find(int Z, int i) {
    int L = -1, R = n;
    while (R - L > 1) {
        int M = (R + L) / 2;
        if (bin[M][i] >= Z) {
            R = M;
        }
        else {
            L = M;
        }
    }
    if (R == n || bin[R][i] != Z) {
        return 1e9;
    }
    return R;
}

int check(int t) {
    w[0] = w[1] = 0;
    L[0] = L[1] = 0;
    bool finished = false;
    for (;;) {
        int R1 = Find(L[0] + t, 0);
        int R2 = Find(L[1] + t, 1);
        if (R1 > n && R2 > n) {
            break;
        }
        if (R1 < R2) {
            ++w[0];
            L[0] = bin[R1][0];
            L[1] = bin[R1][1];
            if (R1 == n - 1) {
                finished = true;
                break;
            }
        }
        else {
            ++w[1];
            L[0] = bin[R2][0];
            L[1] = bin[R2][1];
            if (R2 == n - 1) {
                finished = true;
                break;
            }
        }
    }
    if (finished) {
        if (w[win] > w[1 - win]) {
            ans.push_back(mp(w[win], t));
        }
    }
}

main() {
    //freopen("learning.in", "r", stdin);
    //freopen("learning.out", "w", stdout);
    cin >> n;
    cin >> arr[0];
    --arr[0];
    next[arr[0]].push_back(0);
    ++bin[0][arr[0]];
    For(i, 1, n) {
        cin >> arr[i];
        --arr[i];
        next[arr[i]].push_back(i);
        bin[i][arr[i]] = bin[i - 1][arr[i]] + 1;
        bin[i][1 - arr[i]] = bin[i - 1][1 - arr[i]];
    }
    win = arr[n - 1];
    For(i, 0, n) {
        ++f[arr[i]];
        if (arr[i] == win) {
            check(f[win]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    For(i, 0, ans.size()) {
        cout << ans[i].x << ' ' << ans[i].y << endl;
    }
}