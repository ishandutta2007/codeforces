#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18 + 1;

typedef long long ll;

ll dp[maxn], a[maxn], b[maxn];
deque<pair<ll, ll>> dq;


bool check(const pair<ll, ll>& l1, const pair<ll, ll>& l2, ll x) {
    return l1.first * x + l1.second >= l2.first * x + l2.second;
}

bool cross(const pair<ll, ll>& l1, const pair<ll, ll>& l2, const pair<ll, ll>& l3) {
    return (l2.second - l3.second) / (l3.first - l2.first) <= (l1.second - l3.second) / (l3.first - l1.first);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    b[0] = 1e9 + 10; dp[1] = 0;
    dq.push_back(make_pair(b[0], 0)); dq.push_back(make_pair(b[1], 0));
    for (int i = 2; i <= n; ++i) {
        while (dq.size() >= 2 && check(dq[0], dq[1], a[i])) dq.pop_front();
        dp[i] = dq.front().first * a[i] + dq.front().second;
        while (dq.size() >= 2 && cross(dq[dq.size() - 2], dq[dq.size() - 1], make_pair(b[i], dp[i]))) dq.pop_back();
        dq.push_back(make_pair(b[i], dp[i]));
    }
    cout << dp[n] << endl;
    return 0;
}