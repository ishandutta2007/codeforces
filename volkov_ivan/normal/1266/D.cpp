#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX_N = 3e5 + 7;
int bal[MAX_N];

struct query{
    int a, b, c;
    query() {}
    query(int a, int b, int c): a(a), b(b), c(c) {}
};

vector <pair <int, int>> pl, mn;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(bal, 0, sizeof(bal));
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        bal[a] -= w;
        bal[b] += w;
    }
    for (int i = 1; i <= n; i++) {
        if (bal[i] > 0) {
            pl.push_back({bal[i], i});
        }
        if (bal[i] < 0) {
            mn.push_back({-bal[i], i});
        }
    }
    sort(pl.begin(), pl.end(), greater <pair <int, int>>());
    sort(mn.begin(), mn.end(), greater <pair <int, int>>());
    int l = 0, r = 0;
    int sz = pl.size();
    vector <query> res;
    while (l < sz) {
        while (l < sz && pl[l].first == 0) l++;
        if (l == sz) break; 
        while (mn[r].first == 0) r++;
        int x = min(mn[r].first, pl[l].first);
        res.push_back(query(mn[r].second, pl[l].second, x));
        mn[r].first -= x;
        pl[l].first -= x;
    }
    cout << res.size() << endl;
    for (query elem : res) {
        cout << elem.a << ' ' << elem.b << ' ' << elem.c << "\n";
    }
    return 0;
}