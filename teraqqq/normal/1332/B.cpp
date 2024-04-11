#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

bool is_prime(int n) {
    for(int d = 2; d*d <= n; ++d)
        if(n%d == 0) return false;
    return true;
}

void solve(const vi& p) {
    vector<vi> numbers(p.size());
    int n; cin >> n;
    for(int i = 0, x; i < n; ++i) {
        cin >> x;
        for(int j = 0; j < p.size(); ++j)
            if(x % p[j] == 0) { numbers[j].pb(i); break; }
    }
    vi res(n); int m = 0;
    for(int i = 0; i < p.size(); ++i) {
        if(numbers[i].empty()) continue;
        ++m;
        for(int t : numbers[i]) res[t] = m;
    }

    cout << m << '\n';
    for(int i : res) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vi p;
    for(int i = 2; i*i <= 1000; ++i)
        if(is_prime(i)) p.pb(i);
    int t; cin >> t;
    while(t--) solve(p);
}