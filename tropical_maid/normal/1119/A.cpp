#include <bits/stdc++.h>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
int C[300001];
int L[300001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int ans = -1;
    set<pii> sp;
    for (int i = 1; i <= n; ++i) sp.emplace(L[i] = 1e9, i);
    for (int i = 1; i <= n; ++i) {
        cin >> C[i];
        auto it = sp.begin();
        while (1) {
            if (it->se != C[i]) break;
            ++it;
        }
        ans = max(ans, i - it->fs);
        if (i < L[C[i]]) sp.erase(pii(L[C[i]], C[i])), sp.emplace(L[C[i]] = i, C[i]);
    }
    printf("%d", ans);
    return 0;
}