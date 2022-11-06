#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int ans[maxn << 1];
vector<int> vec[2], pos[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;     
    for (int i = 0; i < 2 * n; ++i) {
        int x; cin >> x;
        pos[x].push_back(i);
    }
    int cur = 0;
    for (int i = 0; i < maxn; ++i) if (pos[i].size() > 1) {
        vec[0].push_back(i); vec[1].push_back(i);
        if (pos[i].size() % 2 == 0) {
            int cnt = 0;
            for (int j : pos[i]) {
                ++cnt;
                if (cnt > pos[i].size() / 2) ans[j] = ((cur ^ 1) + 1);
                else ans[j] = cur + 1;
            }
        } else {
            int cnt = 0;
            for (int j : pos[i]) {
                ++cnt;
                if (cnt > pos[i].size() / 2 + 1) ans[j] = ((cur ^ 1) + 1);
                else ans[j] = cur + 1;
            }
            cur ^= 1;
        }
    }
    for (int i = 0; i < maxn; ++i) if (pos[i].size() == 1) {
        ans[pos[i][0]] = cur + 1;
        vec[cur].push_back(i);
        cur ^= 1;
    }
    vec[0].resize(unique(vec[0].begin(), vec[0].end()) - vec[0].begin()); vec[1].resize(unique(vec[1].begin(), vec[1].end()) - vec[1].begin());
    cout << vec[0].size() * vec[1].size() << endl;
    for (int i = 0; i < 2 * n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}