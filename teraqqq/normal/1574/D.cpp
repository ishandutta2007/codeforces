#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int N = 10;

int n, m;
vector<int> a[N];
set<vector<int>> b, was;

int get_sum(const vector<int>& v) {
    int s = 0;
    for (int i = 0; i < n; ++i) s += a[i][v[i]];
    return s;
}

struct cmp {
    bool operator () (const vector<int>& u, const vector<int>& s) const {
        return get_sum(u) < get_sum(s);
    }
};

priority_queue<vi, vector<vi>, cmp> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    vector<int> v0;

    for (int i = 0; i < n; ++i) {
        int c; cin >> c; a[i].resize(c);
        for (int& x : a[i]) cin >> x;
        v0.push_back(c - 1);
    }

    q.push(v0);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        vector<int> t(n);
        for (int& x : t) cin >> x, --x;
        b.insert(t);
    }

    while (true) {
        auto v = q.top(); q.pop();

        if (b.count(v)) {
            for (int i = 0; i < n; ++i) {
                if (v[i] == 0) continue;

                v[i]--;
                if (was.count(v) == 0) {
                    was.insert(v);
                    q.push(v);
                }
                v[i]++;
            }
        } else {
            for (int x : v) cout << x+1 << ' ';
            cout << endl;
            break;
        }
    }
}