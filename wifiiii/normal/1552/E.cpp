#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n * k);
    for(int i = 0; i < a.size(); ++i) cin >> a[i], --a[i];
    vector<vector<int>> pos(n);
    for(int i = 0; i < a.size(); ++i) {
        pos[a[i]].push_back(i);
    }
    vector<int> use(n);
    vector<pair<int,int>> ans(n);
    for(int i = 1; i < k; ++i) {
        vector<int> ord;
        for(int j = 0; j < n; ++j) {
            if(use[j]) continue;
            ord.push_back(j);
        }
        sort(ord.begin(), ord.end(), [&](int x, int y) {return pos[x][i] < pos[y][i];});
        for(int j = 0; j < (n + k - 2) / (k - 1); ++j) {
            if(j == ord.size()) break;
            use[ord[j]] = 1;
            ans[ord[j]].first = pos[ord[j]][i-1];
            ans[ord[j]].second = pos[ord[j]][i];
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
    }
}