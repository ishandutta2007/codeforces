#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7, M = 5e5 + 7;
int mini[N];
vector <int> pr;
pair <int, int> res[M];

void init() {
    int n = N - 5;
    for (int i = 1; i <= n; i++) {
        mini[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        if (mini[i] == 0) {
            pr.push_back(i);
            mini[i] = i;
        }
        for (int elem : pr) {
            if (elem > mini[i] || elem * i > n) break;
            int cur = elem * i;
            if (elem == mini[i]) {
                mini[cur] = elem;
            } else {
                mini[cur] = elem;
            }
        }
    }
}

signed main() {
    init();
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int d = mini[x];
        int a = d, b = x / d;
        while (b % d == 0) {
            a *= d;
            b /= d;
        }
        //cout << a << ' ' << b << endl;
        if (b == 1) {
            res[i] = {-1, -1};
        } else {
            res[i] = {a, b};
        }
    }
    for (int i = 0; i < n; i++) cout << res[i].first << ' ';
    cout << "\n";
    for (int i = 0; i < n; i++) cout << res[i].second << ' ';
}