#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], cnt[maxn], ans[maxn];
vector<int> pos[maxn];
bool used[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        pos[a[i]].push_back(i);
    }
    vector<int> v1, v2;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 1) {
            for (int u : pos[i]) v1.push_back(u);
        }
        if (cnt[i] == 0) v2.push_back(i);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ind = 0, cur = 0;
    for (int i : v1) {
        if (used[a[i]]) {
            --cnt[a[i]]; a[i] = v2[ind];
            ++cur;
            ++ind;
            continue;
        }
        if (cnt[a[i]] == 1) continue;
        if (a[i] < v2[ind]) {
            used[a[i]] = true;;
            continue;
        }
        --cnt[a[i]]; a[i] = v2[ind];
        ++cur;
        ++ind;
    }
    cout << cur << endl;
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << endl;
    return 0;
}