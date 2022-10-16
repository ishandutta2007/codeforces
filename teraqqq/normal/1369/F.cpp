#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

int win_lose(int a, int b, ll r, ll s) {
    for(; s <= r; r >>= 1) {
        if(a) {
            if(b) a = r&1, b = ~r&1;
            else return (s&1) ? b : a;
        }
        else a = b = 1;
    }
    return (s&1) ? b : a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vi w(n), l(n);
    for(int i = 0; i < n; ++i) {
        ll s, e; cin >> s >> e;
        w[i] = win_lose(1, 1, e, s);
        l[i] = win_lose(0, 0, e, s);
    }
    for(int i = n-1; i--; ) {
        const int W = w[i], L = l[i];
        w[i] = (W && !w[i+1]) || (L && w[i+1]);
        l[i] = (W && !l[i+1]) || (L && l[i+1]);
    }
    cout << w[0] << ' ' << l[0] << endl;
}