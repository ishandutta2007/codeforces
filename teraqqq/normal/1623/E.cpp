#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, k, good_idea[N];
int go_left[N], go_right[N];
string res, s;

void make_tour(int v, vector<int>& out) {
    if (v != 0) {
        make_tour(go_left[v], out);
        out.push_back(v);
        make_tour(go_right[v], out);
    }
}

int solve(int v, int k) {
    if (v == 0) return 0;

    int writed = 0;

    if (k == 0) {
        solve(go_left[v], 0);
        res.push_back(s[v]);
        solve(go_right[v], 0);
        return 0;
    } else {
        writed = solve(go_left[v], k-1);

        res.push_back(s[v]);
        if (writed != 0 || good_idea[v]) {
            ++writed;
            res.push_back(s[v]);
            writed += solve(go_right[v], k - writed);
        } else {
            solve(go_right[v], 0);
        }
    }

    return writed;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    cin >> s; s.insert(s.begin(), '$');
    for (int i = 1; i <= n; ++i) {
        cin >> go_left[i] >> go_right[i];
    }

    vector<int> tour;
    make_tour(1, tour);
    tour.push_back(0);

    for (int i = 0; i < n; ) {
        int j = i;
        while (s[tour[i]] == s[tour[j]]) ++i;

        if (s[tour[j]] < s[tour[i]]) {
            for (int t = j; t < i; ++t) good_idea[tour[t]] = true;
        }
    }

    solve(1, k);

    cout << res << '\n';
}