#include <bits/stdc++.h>
using namespace std;

vector<int> ft;

int query(int a) {
    int res = 0;
    for ( ; a >= 0; a = (a & (a + 1)) - 1) {
        res += ft[a];
    }
    return res;
}

void update(int a, int addend) {
    for ( ; a < ft.size(); a = (a | (a + 1))) {
        ft[a] += addend;
    }
}

int getNdx(int a) {
    int lo = 0, hi = ft.size() - 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (query(mi) >= a) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    int m;
    cin >> m;
    vector<tuple<int, int, int>> query(m);
    for (auto& i : query) {
        cin >> get<0>(i) >> get<1>(i);
    }
    for (int i = 0; i < m; ++i) {
        get<2>(query[i]) = i;
    }

    vector<pair<int, int>> ndx(n);
    for (int i = 0; i < n; ++i) {
        ndx[i] = {-a[i], i};
    }
    sort(ndx.begin(), ndx.end(), greater<pair<int, int>>());
    sort(query.begin(), query.end(), greater<tuple<int, int, int>>());

    ft.resize(n);
    for (int i = 0; i < n; ++i) {
        update(i, 1);
    }

    int j = 0;
    vector<int> ans(m);
    for (int i = 0; i < n; ++i) {
        while (j < m && get<0>(query[j]) == n - i) {
            ans[get<2>(query[j])] = a[getNdx(get<1>(query[j]))];
            ++j;
        }
        update(ndx[i].second, -1);
    }
    for (auto i : ans) {
        cout << i << '\n';
    }
}