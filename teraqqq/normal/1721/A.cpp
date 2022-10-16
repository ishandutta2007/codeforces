#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T>;

void solve() {
    string a, b; cin >> a >> b;
    map<char, int> cnt;
    for (char x : a) cnt[x]++;
    for (char x : b) cnt[x]++;
    vector<int> kek;
    for (auto [_, k] : cnt) kek.push_back(k);
    sort(kek.begin(), kek.end());

    int ans = 0;
    for (int i = 0; i + 1 < kek.size(); ++i) {
        ans += (kek[i] + 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}