#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ord(n), rord(n);
    iota(ord.begin(), ord.end(), 0);
    stable_sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j];});
    for(int i = 0; i < n; ++i) rord[ord[i]] = i;
    stable_sort(a.begin(), a.end());
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < a[i]; ++j) ans[j][i] = 1;
    }
    int cur = 0;
    vector<int> qwq(n);
    int m = n;
    vector<int> r(n, -1);
    for(int i = 0; i < n; ++i) {
        if(count(ans[i].begin(), ans[i].end(), 1) == 0) break;
        int p = find(ans[i].begin(), ans[i].end(), 1) - ans[i].begin();
        if(ans[i][i] != 1) {
            for(int j = i - 1; j >= 0; --j) {
                if(ans[j][i] == 1 && r[j] != i) {
                    ans[j][i] = 0;
                    ans[i][i] = 1;
                    break;
                }
            }
        } else {
            if(p < i) {
                ans[i][i] = 0;
                qwq[i] = 1;
            }
        }
        for(int j = 0; j < n; ++j) if(ans[i][j] == 1) {r[i] = j; break;}
    }
    int cnt = 0;
    if(count(qwq.begin(), qwq.end(), 1)) ++cnt;
    for(int i = 0; i < n; ++i) if(count(ans[i].begin(), ans[i].end(), 1)) ++cnt;
    cout << cnt << '\n';
    if(count(qwq.begin(), qwq.end(), 1)) {
        for(int i = 0; i < n; ++i) cout << qwq[rord[i]]; cout << '\n';
    }
    for(int i = 0; i < n; ++i) {
        if(count(ans[i].begin(), ans[i].end(), 1)) {
            for(int j = 0; j < n; ++j) cout << ans[i][rord[j]];
            cout << '\n';
        }
    }
}