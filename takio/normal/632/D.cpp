#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
vector <int> c[N];
int cnt[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, flag = 0, x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &x);
        if (x > m) continue;
        flag = 1;
        c[x].push_back (i);
    }
    if (flag == 0) {
        cout << "1 0";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int sz = c[i].size();
        for (int j = i; j <= m; j += i) {
            cnt[j] += sz;
        }
    }
    int p = -1;
    for (int i = 1; i <= m; i++) if (p == -1 || cnt[i] > cnt[p]) {
        p = i;
    }
    vector <int> r;
    for (int i = 1; i <= m; i++) if (p % i == 0) {
        for (int j = 0; j < c[i].size(); j++) {
            r.push_back (c[i][j]);
        }
    }
    sort (r.begin(), r.end());
    cout << p << ' ' << r.size() << endl;
    for (int i = 0; i < r.size(); i++) printf ("%d ", r[i]);
}