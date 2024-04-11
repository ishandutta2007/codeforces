#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn], b[maxn], p[maxn];
bool v[maxn], ok[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> pos, left;
    for (int i = 0; i < n; ++i) if (a[i] == b[i]) v[i] = true;
    for (int i = 0; i < n; ++i) if (v[i]) p[i] = a[i], ok[p[i]] = true;
    for (int i = 0; i < n; ++i) if (!v[i]) pos.push_back(i);
    for (int i = 1; i <= n; ++i) if (!ok[i]) left.push_back(i);
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        if (left.size() < 2 || pos.size() < 2) {
            if (a[i] == b[i]) pos.push_back(i), left.push_back(a[i]), flag = true;
            else continue;
        } 
        bool suc = true;
        if (left[0] == a[pos[0]] && left[1] == a[pos[1]] || left[0] == b[pos[0]] && left[1] == b[pos[1]]) swap(left[0], left[1]);
        if (left[0] != a[pos[0]] && left[1] != a[pos[1]] || left[0] != b[pos[0]] && left[1] != b[pos[1]]) swap(left[0], left[1]);
        if (left[0] == a[pos[0]] && left[1] == a[pos[1]] || left[0] == b[pos[0]] && left[1] == b[pos[1]]) suc = false;
        if (left[0] != a[pos[0]] && left[1] != a[pos[1]] || left[0] != b[pos[0]] && left[1] != b[pos[1]]) suc = false;
        if (suc) { p[pos[0]] = left[0]; p[pos[1]] = left[1]; break; }
        if (flag) pos.pop_back(), left.pop_back();
    }
    for (int i = 0; i < n; ++i) cout << p[i] << ' '; cout << endl;
    return 0;
}