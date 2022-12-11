#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#define int long long

using namespace std;

const int MAX_N = 1e6 + 7;
int pref[MAX_N], res[MAX_N];

struct update{
    char t;
    int pos, val;
    update(char t, int pos, int val): t(t), pos(pos), val(val) {}
};

bool cmp(update a, update b) {
    if (a.pos == b.pos) {
        if (a.t == '+' && b.t == '-') return 1;
    }
    return (a.pos < b.pos);
}

void add(vector <update> &v, int l, int r, int val) {
    v.push_back(update('+', l, val));
    v.push_back(update('-', r, val));
}

void make_one(int w, int n) {
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <update> v;
    add(v, 0, w - n, 0);
    add(v, n, w, 0);
    for (int i = 0; i < n; i++) add(v, i, w - n + i + 1, a[i]);
    sort(v.begin(), v.end(), cmp);
    map <int, int, greater <int>> all;
    //multiset <int, greater <int>> all;
    int pos = 0, val = 0;
    for (update upd : v) {
        pref[pos] += val;
        pref[upd.pos] -= val;
        if (upd.t == '+') all[upd.val]++;
        else if (--all[upd.val] == 0) all.erase(all.find(upd.val));
        pos = upd.pos;
        val = (all.empty() ? 0 : (*all.begin()).first);
    }
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w;
    cin >> n >> w;
    memset(res, 0, sizeof(res));
    memset(pref, 0, sizeof(pref));
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        make_one(w, sz);
    }
    res[0] = pref[0];
    for (int i = 1; i < w; i++) {
        res[i] = res[i - 1] + pref[i];
    }
    for (int i = 0; i < w; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}