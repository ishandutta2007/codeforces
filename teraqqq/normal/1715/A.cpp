#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

void solve() {
    int n, m; cin >> n >> m;
    n--, m--;
    cout << min(n+m+min(n,m)+1, 2*n+2*m) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}