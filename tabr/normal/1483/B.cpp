#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> nxt(n);
        iota(nxt.begin(), nxt.end(), 1);
        nxt.back() = 0;
        vector<int> pre(n);
        iota(pre.begin(), pre.end(), -1);
        pre[0] = n - 1;
        vector<int> ans;
        queue<int> que;
        for (int i = 0; i < n; i++) {
            que.emplace(i);
        }
        vector<int> del(n);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            if (del[p]) {
                continue;
            }
            if (__gcd(a[p], a[nxt[p]]) == 1) {
                ans.emplace_back(nxt[p] + 1);
                del[nxt[p]] = 1;
                pre[nxt[nxt[p]]] = p;
                nxt[p] = nxt[nxt[p]];
                que.emplace(p);
            }
        }
        cout << ans.size() << " ";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}