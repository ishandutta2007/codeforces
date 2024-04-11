#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/10/20, 19:03:18
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, p;
int T[100001];
llong A[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p;
    priority_queue<llong> e;
    vector<pii> ts;
    for (int i = 1; i <= n; ++i) {
        cin >> T[i];
        e.push(-T[i]);
        ts.emplace_back(T[i], i);
    }
    sort(ts.rbegin(), ts.rend());
    queue<int> q;
    set<int> em;
    priority_queue<int> g;
    while (!e.empty()) {
        llong t = -e.top();
        e.pop();
        while (!ts.empty() && ts.back().fs <= t) {
            g.emplace(-ts.back().se);
            ts.pop_back();
        }
        if (!q.empty() && A[q.front()] == t) {
            em.erase(q.front());
            q.pop();
            if (!q.empty()) {
                A[q.front()] = t + p;
                e.push(-(t + p));
            }
        }
        if (!g.empty()) {
            int x = -g.top();
            if (!em.empty() && *em.begin() < x) continue;
            g.pop();
            em.insert(x);
            if (q.empty()) A[x] = t + p, e.push(-(t + p));
            q.push(x);
        }
    }
    for (int i = 1; i <= n; ++i) printf("%lld ", A[i]);
    return 0;
}