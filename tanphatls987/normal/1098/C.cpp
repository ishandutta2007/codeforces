#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define X first
#define Y second

const int N = 2e5 + 10;
ll n, need;
ll depth[N], deg[N];
ll p[N];
ll tar[N];

ll getWeight(ll mid) {
    ll ans = 0;
    for(ll i = 1, cur = 1, rem = n; rem ; i++, cur *= mid){ 
        ll use = min(cur, rem); 
        ans += use * i;
        rem -= use;
    }
    return ans;
}
void buildAnswer(ll branch) {
    cout << "Yes\n";
    deg[1] = 0;
    depth[1] = 1;
    for(int i = 2, use = 1; i <= n; i++) {
        while (deg[use] == branch) use++; 
        deg[use]++;
        depth[i] = depth[use] + 1;
        p[i] = use;
    }
    for(int i = 1; i <= n; i++) need -= depth[i];

    priority_queue<pll> pq;
    for(int i = 1; i < n; i++) if (deg[i] == 0) 
        pq.push(pll(depth[i], i));
    int top = depth[n];
    for(int i = depth[n], cur = n; i >= 1; i--) {
        tar[i] = cur;
        cur = p[cur];
    }
    while (need) {
        auto cur = pq.top(); pq.pop();
        while (top - depth[cur.Y] + 1 > need) top--;

        need -= top - depth[cur.Y] + 1;

        deg[p[cur.Y]]--;
        if (!deg[p[cur.Y]]) pq.push(pll(depth[p[cur.Y]], p[cur.Y]));
        p[cur.Y] = tar[top];
        depth[cur.Y] = depth[tar[top] + 1];
        tar[++top] = cur.Y;
    }

    for(int i = 2; i <= n; i++) cout << p[i] << " ";
}
/*
pll build(ll depth) {
    ll rem = need - depth * (depth + 1) / 2;
    if (rem < 0) return pll(n + 1, -1);
    if ((n - depth) * depth < rem) return pll(n + 1, -1);

    ll L = , R = n - depth;
    while (L <= R) {
        ll mid = (L + R) / 2;
        if (get(mid, depth, n - depth) < rem) L = mid + 1;
        else R = mid - 1;
    }
    return pll(L, depth);
}
*/
void solve() {
    if (need < 2 * n - 1 || need > n * (n + 1) / 2) {
        cout << "No";
        return;
    }
    ///depth = n
    if (need == n * (n + 1) / 2) {
        cout << "Yes\n";
        for(int i = 2; i <= n; i++) cout << i - 1 << " ";
        return;
    }
    ll L = 2, R = n - 1; 
    while (L <= R) {
        ll mid = (L + R) / 2;
        if (getWeight(mid) <= need) R = mid - 1;
        else L = mid + 1;
    }
    buildAnswer(L);
}
int main() {
    cin >> n >> need;
    solve();
}