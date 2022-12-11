#include <bits/stdc++.h>
//#define int long long

using namespace std;

vector <vector <int>> res;

void solve(vector <pair <int, int>> perm) {
    int n = perm.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (perm[i].first == 1 + perm[j].first) {
                int val = perm[j].first;
                vector <pair <int, int>> perm2;
                vector <int> cur;
                int sm = 0;
                for (int t = 0; t < i; t++) sm += perm[t].second;
                if (sm != 0) cur.push_back(sm);
                cur.push_back(perm[i].second);
                sm = 0;
                for (int t = i + 1; t <= j; t++) sm += perm[t].second;
                if (sm != 0) cur.push_back(sm);
                sm = 0;
                for (int t = j + 1; t < n; t++) sm += perm[t].second;
                if (sm != 0) cur.push_back(sm);
                for (int t = j + 1; t < n; t++) {
                    perm2.push_back(perm[t]);
                    if (perm[t].first > val) perm2.back().first--;
                }
                for (int t = i + 1; t <= j; t++) {
                    perm2.push_back(perm[t]);
                    if (perm[t].first > val) perm2.back().first--;
                }
                perm2.back().second += perm[i].second;
                for (int t = 0; t < i; t++) {
                    perm2.push_back(perm[t]);
                    if (perm[t].first > val) perm2.back().first--;
                }
                res.push_back(cur);
                solve(perm2);
                return;
            }
        }
    }
}


signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    vector <pair <int, int>> perm;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        perm.push_back({a, 1});
    }
    solve(perm);
    cout << res.size() << endl;
    for (auto elem : res) {
        cout << elem.size() << ' ';
        for (auto elem2 : elem) {
            cout << elem2 << ' ';
        }
        cout << "\n";
    }
    return 0;
}