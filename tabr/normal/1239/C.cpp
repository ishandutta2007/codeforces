#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, p;
    cin >> n >> p;
    vector<ll> t(n), ans(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        pq.push({t[i], i + 1});
    }
    set<int> sit, wait;
    ll lst = *min_element(t.begin(), t.end());
    while (!pq.empty()) {
        ll now = pq.top().first;
        int i = pq.top().second;
        debug(now, sit, lst);
        if (!sit.empty() && ((lst <= now && *sit.begin() < i) || lst < now)) {
            pq.push({lst, *sit.begin()});
            sit.erase(*sit.begin());
            continue;
        }
        i = abs(i);
        debug(i);
        pq.pop();
        ans[i - 1] = now + p;
        lst = max(lst, now + p);
        pq.push({now + p, -i});
        wait.emplace(i);
        while (pq.top().second != -i) {
            if (pq.top().second < *wait.begin()) {
                wait.emplace(pq.top().second);
            } else {
                sit.emplace(pq.top().second);
            }
            pq.pop();
        }
        wait.erase(i);
        pq.pop();
        if (!wait.empty()) {
            pq.push({now + p, -*wait.rbegin()});
            wait.erase(*wait.rbegin());
        }
    }
    while (!sit.empty()) {
        lst += p;
        ans[*sit.begin() - 1] = lst;
        sit.erase(*sit.begin());
    }

    for (ll i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}