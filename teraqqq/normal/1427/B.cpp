#include <bits/stdc++.h>

#define F first
#define S second

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize

#define pq_min(T) priority_queue<T, vector<T>, greater<T>>
#define pq_max(T) priority_queue<T, vector<T>, less<T>>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using ld = long double;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

bool check(const vi& b) {
    int sum = 0;
    for(int i : b) if((sum += i) == 0) return false;
    return true;
}

void solve() {
    int n, k; cin >> n >> k;
    pq_max(pi) q;
    string s; cin >> s;

    int res = 0, m = 0; vi v;
    for(int i = 0, t = 0; i < n; ++i) {
        if(s[i] == 'L') ++t, ++m;
        else {
            res += 2;
            if(i != t && t) v.pb(t);
            if(!i || t) --res;
            t = 0;
        }
    }

    if(!res) --res;
    res += 2 * min(m, k);

    sort(all(v));
    for(int i : v) if(i <= k) res++, k -= i;

    cout << max(0, res) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}