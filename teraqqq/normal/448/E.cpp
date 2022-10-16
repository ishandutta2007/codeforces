#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const int LIMIT = 1e5;

map<ll, vector<ll>> mdiv;
vector<ll> ans;

void answer(ll x, ll k) {
    if (ans.size() >= LIMIT) return;
    if (x == 1 || k == 0) {
        ans.push_back(x);
    } else {
        for (int i = 0; i < mdiv[x].size(); ++i) {
            const ll d = mdiv[x][i];
            answer(d, k-1);
            if (ans.size() >= LIMIT) return;
        }
    }
}

void solve() {
    ll x, k; cin >> x >> k;
    vector<ll> div;
    for (ll d = 1; d*d <= x; ++d) {
        if (x % d != 0) continue;
        div.push_back(d);
        if (d*d != x) div.push_back(x/d);
    }
    sort(div.begin(), div.end());

    for (ll x : div) {
        vector<ll> u;
        for (ll y : div) {
            if (x/y < y) break;

            if (x % y == 0) {
                u.push_back(y);
                if (y*y != x) u.push_back(x/y);
            }
        }
        sort(u.begin(), u.end());
        mdiv[x] = u;
    }

    answer(x, k);
    for (ll t : ans) cout << t << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) solve();
}