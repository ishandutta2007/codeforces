#include <bits/stdc++.h>
using namespace std;

vector<int> pr;
vector<vector<int>> adj(100000);
vector<int> idx(1000000);
vector<bool> prime(1000000, 1);
int x = 0;
int main() {
    pr.push_back(1);
    for (int i = 2; i < 1000; i++) {
        bool p = true;
        for (int j = 2; j < i; j++)
            if (i % j == 0) p = false;
        if (p) pr.push_back(i);
    }
    for (int i = 2; i < 1000000; i++) {
        if (prime[i]) {
            idx[i] = ++x;
            for (int j = 2 * i; j < 1000000; j += i)
                prime[j] = false;
        }
    }
    //create idx
    int n; cin >> n;
    vector<int> a(n);
    int ans = 2000000;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int x : pr) {
            if (x == 1) continue;
            while (a[i] % (x * x) == 0)
                a[i] /= (x * x);
        }
        bool found = false;
        for (int x : pr) {
            if (x == 1) continue;
            if (a[i] % x == 0 && a[i] != x) {
                found = true;
                adj[idx[x]].push_back(idx[a[i] / x]);
                adj[idx[a[i] / x]].push_back(idx[x]);
                break;
            }
        }
        if(!found) {
            adj[idx[a[i]]].push_back(0);
            adj[0].push_back(idx[a[i]]);
        }
    }
    for (int i : pr) {
        queue<int> q;
        q.push(idx[i]);
        vector<int> dist(100000, -1);
        dist[idx[i]] = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
                else if (dist[next] >= dist[curr]) {
                    ans = min(ans, 1 + dist[curr] + dist[next]);
                }
            }
        }
    }
    if (ans > 1000000) cout << -1 << "\n";
    else cout << ans << "\n";
}