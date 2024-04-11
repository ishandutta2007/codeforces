#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 21) + 7;
int f[N], whereis[N];
bool used[N];
long long summ = 0;

int rec(int pos, int lvl, int h, int g, vector <int> &have) {
    vector <int> left, right;
    int mini = 0;
    if (lvl != h) {
        mini = max(mini, rec(2 * pos, lvl + 1, h, g, left));
        mini = max(mini, rec(2 * pos + 1, lvl + 1, h, g, right));
        have.resize(left.size() + right.size());
        merge(left.begin(), left.end(), right.begin(), right.end(), have.begin());
    }
    have.push_back(f[pos]); 
    int res = 0;
    if (lvl <= g) {
        int uk = upper_bound(have.begin(), have.end(), mini) - have.begin();
        res = have[uk];
        summ += have[uk];
    }
    used[res] = 1;
    return res;
}

void kek(int pos) {
    int lft = 2 * pos, rght = 2 * pos + 1;
    if (f[lft] == 0 && f[rght] == 0) {
        f[pos] = 0;
        return;
    }
    if (f[lft] > f[rght]) {
        f[pos] = f[lft];
        whereis[f[lft]] = pos;
        kek(lft);
    } else {
        f[pos] = f[rght];
        whereis[f[rght]] = pos;
        kek(rght);
    }
}

void solve() {
    summ = 0;
    int h, g;
    cin >> h >> g;
    int n = (1 << h) - 1;
    vector <int> cur;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        whereis[f[i]] = i;
        cur.push_back(f[i]);
    }
    vector <int> now;
    rec(1, 1, h, g, now);
    cout << summ << "\n";
    for (int elem : cur) {
        if (!used[elem]) {
            cout << whereis[elem] << ' ';
            kek(whereis[elem]);
        }
    }
    cout << "\n";
    for (int elem : cur) used[elem] = 0;
    for (int i = 1; i <= n; i++) f[i] = 0;
}

int main() {
    memset(f, 0, sizeof(f));
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}