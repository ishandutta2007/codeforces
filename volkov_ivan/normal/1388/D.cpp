#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int a[N], b[N], deg[N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    memset(deg, 0, sizeof(deg));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1) deg[--b[i]]++;
    }
    int res = 0;
    vector <int> fi, se;
    vector <int> lst;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) lst.push_back(i);
    }
    while (!lst.empty()) {
        int v = lst.back();
        lst.pop_back();
        res += a[v];
        if (a[v] >= 0) fi.push_back(v);
        else se.push_back(v);
        if (b[v] != -1) {
            if (a[v] >= 0) a[b[v]] += a[v];
            if (--deg[b[v]] == 0) lst.push_back(b[v]);
        }
    }
    cout << res << endl;
    reverse(se.begin(), se.end());
    for (int elem : fi) cout << elem + 1 << ' ';
    for (int elem : se) cout << elem + 1 << ' ';
    cout << endl;
    return 0;
}