#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> a, pref, b;
int n, m;

void build(vector <vector <int>> &now) {
    pref.assign(n + 2, vector <int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + now[i][j];
        }
    }
}

bool ok(int x, int y) {
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}

int get(int l1, int r1, int l2, int r2) {
    l1 = max(l1, 1);
    l2 = min(l2, n);
    r1 = max(r1, 1);
    r2 = min(r2, m);
    //if (!ok(l1, r1) || !ok(l2, r2)) return 0;
    return pref[l2][r2] - pref[l1 - 1][r2] - pref[l2][r1 - 1] + pref[l1 - 1][r1 - 1];
}

bool check(int mid) {
    build(a);
    b.assign(n + 2, vector <int>(m + 2, 0));
    int need = (2 * mid + 1) * (2 * mid + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (get(i - mid, j - mid, i + mid, j + mid) == need) b[i][j] = 1;
        }
    }
    build(b);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool fire = (get(i - mid, j - mid, i + mid, j + mid) > 0);
            //if (mid == 1) cout << i << ' ' << j << ' '<< fire << endl;
            if (fire && a[i][j] == 0) return 0;
            if (!fire && a[i][j] == 1) return 0;
        }
    }
    return 1;
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.assign(n + 2, vector <int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == 'X') a[i][j] = 1;
        }
    }
    int l = 0, r = n + 10, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    check(l);
    cout << l << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] == 1) cout << 'X';
            else cout << '.';
        }
        cout << "\n";
    }
    return 0;
}