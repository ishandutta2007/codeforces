#include <bits/stdc++.h>
//#define int long long

using namespace std;

vector <vector <int>> try_hard(int n, int k, int t) {
    if ((t * k) % 2 != n % 2)
        return {};

    vector <vector <int>> cur(t);
    vector <vector <int>> ans;
    int rest = t * k - n;
    assert(rest >= 0 && rest % 2 == 0);
    for (int i = 1; i <= n; i++) {
        if (cur.empty())
            return {};

        int max_ch = cur.size() - 1;
        if (max_ch % 2 == 1)
            max_ch--;

        int cnt = min(max_ch, rest);
        rest -= cnt;
        for (int j = 0; j <= cnt; j++) {
            cur[j].push_back(i);
        }
        sort(cur.begin(), cur.end(), [](vector<int> &a, vector <int> &b) { return a.size() < b.size(); });
        while (!cur.empty() && (int) cur.back().size() == k) {
            ans.push_back(cur.back());
            cur.pop_back();
        }
    }
    if (!cur.empty() || rest != 0)
        return {};
    return ans;
}

vector <vector <int>> solve0(int n, int k) {
    int st = n / k;
    if (n % k != 0)
        st++;
    for (int i = 0; i < 5; i++) {
        //cout << n << ' ' << k << ' ' << st + i << endl;
        auto res = try_hard(n, k, st + i);
        //cout << "<>" << n << ' ' << k << ' ' << st + i << endl;
        if (!res.empty())
            return res;

    }
    return {};
}

vector <vector <int>> solve(int n, int k) {
    auto r1 = solve0(n, k);
    vector <vector <int>> r2 = {};
    if (k % 2 == 1 && n % 2 == 0)
        r2 = solve0(n, n - k);
    assert(!r1.empty() || !r2.empty());
    if (r2.empty())
        return r1;
    if (!r1.empty() && r1.size() <= r2.size())
        return r1;
    vector <vector <int>> ans;
    for (auto elem : r2) {
        vector <int> cur;
        vector <bool> used(n + 1, 0);
        for (auto elem2 : elem)
            used[elem2] = 1;
        for (int i = 1; i <= n; i++) {
            if (!used[i])
                cur.push_back(i);
        }
        ans.push_back(cur);
    }
    return ans;
}

void proceed(vector <vector <int>> res) {
    /*for (auto elem : res) {
        for (auto elem2 : elem) {
            cout << elem2 << ' ';
        }
        cout << endl;
    }*/
    long long ans = 0;
    for (auto elem : res) {
        cout << "? ";
        for (auto elem2 : elem) {
            cout << elem2 << ' ';
        }
        cout << endl;
        long long x;
        cin >> x;
        ans ^= x;
    }
    cout << "!" << ' ' << ans << endl;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*for (int n = 2; n <= 100; n++) {
        for (int k = 1; k <= n; k++) {

            if (k % 2 == 0 && n % 2 == 1) {
                continue;
            }
            cout << n << ' ' << k << endl;
            solve(n, k);
        }
    }*/
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0 && n % 2 == 1) {
        cout << "-1" << endl;
        return 0;
    }
    proceed(solve(n, k));
    return 0;
}