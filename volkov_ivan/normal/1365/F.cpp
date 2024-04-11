#include <bits/stdc++.h>
#define int long long

using namespace std;

const int b = 239, M = 1e9 + 7;

vector <int> swp(vector <int> a, int k) {
    int n = a.size();
    for (int i = 0; i < k; i++) {
        swap(a[i], a[n - k + i]);
    }
    return a;
}

int hsh(vector <int> a) {
    int h = 0;
    for (int elem : a) {
        h *= b;
        h += elem;
        h %= M;
    }
    return h;
}

vector <vector <int>> all;

unordered_set <int> vis;

void dfs(vector <int> a) {
    int n = a.size();
    vis.insert(hsh(a));
    all.push_back(a);
    cout << endl;
    for (int k = 1; k <= n / 2; k++) {
        vector <int> nxt = swp(a, k);
        //for (int i = 0; i < n; i++) cout << a[i] << ' ';
        if (vis.find(hsh(nxt)) == vis.end()) {
            dfs(nxt);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector <pair <int, int>> aa, bb;
    if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
        cout << "No" << endl;
        return;
    }
    for (int i = 0; i < n / 2; i++) {
        aa.push_back({min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])});
        bb.push_back({min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])});
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    if (aa == bb) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}