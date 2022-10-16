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
    int n; cin >> n;
    vi a(n); for(int& x : a) cin >> x;
    sort(all(a));
    if(check(a)) { cout << "YES" << endl; for(int i : a) cout << i << ' '; cout << endl; return; }
    sort(rall(a));
    if(check(a)) { cout << "YES" << endl; for(int i : a) cout << i << ' '; cout << endl; return; }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}