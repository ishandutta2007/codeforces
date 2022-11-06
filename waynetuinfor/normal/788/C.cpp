#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
int dis[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];
    sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end()) - a.begin());
    queue<int> q;
    fill(dis, dis + maxn, -1);
    for (int i : a) if (i >= n) dis[i - n] = 1, q.push(i - n);
    while (q.size()) {
        int p = q.front(); q.pop();
        for (int i : a) {
            int to = i + p - n;
            if (to >= 0 && to < maxn * 2) {
                if (dis[to] != -1) continue;
                dis[to] = dis[p] + 1;
                q.push(to);
            }
        } 
    }
    cout << dis[0] << endl;
    return 0;
}