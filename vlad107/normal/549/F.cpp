#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

const int N = 3e5 + 100;
const int M = 1e6 + 100;

int n, k;
int a[N], ta[N], nxt[N], prv[N];
int cnt[M];
vector< pair<int, int> > v;
vector< pair<int, int> > q[N];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ta[i + 1] = (ta[i] + a[i]) % k;
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) { nxt[i] = i + 1; prv[i] = i - 1; }
    for (int i = 0; i < v.size(); i++) {
        int x = v[i].second;
        int e = v[i].first % k;
        int l = prv[x];
        int r = nxt[x];
        prv[nxt[x]] = prv[x];
        if (prv[x] != -1) nxt[prv[x]] = nxt[x];
        // u in [l+1..x]
        // v in [x+1..r]
        if (x - l < r - x) {
            for (int u = l+1; u <= x; u++) {
                int need = (ta[u] + e) % k;
                q[x+1].push_back(make_pair(-1, need));
                q[r+1].push_back(make_pair(+1, need));
            }
        } else {
            for (int v = x+1; v <= r; v++) {
                int need = (ta[v] - e + k) % k;
                q[l+1].push_back(make_pair(-1, need));
                q[x+1].push_back(make_pair(+1, need));
            }
        }
    }
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j < q[i].size(); j++) {
            ans += q[i][j].first * cnt[q[i][j].second];
        }
        cnt[ta[i]]++;
    }
    cout << ans - n << endl;
}