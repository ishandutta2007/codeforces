#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using ll = long long;

template<class T> bool ckmin(T&a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T&a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;
template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9+7;

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    assert(a != b);
    assert(1 <= a && a <= (int)2e9);
    assert(1 <= b && b <= (int)2e9);
    int x; cin >> x;
    return x;
}

void solve() {
    const int W = 1 << 30;

    int a = 0;

    for (int t = 0; t < 30; ++t) {
        if (a == 0) {
            a += 1 << t;
            if (ask(a, a + W) % (1 << t + 1) != 0) {
                a -= 1 << t;
            }
        } else {
            if (ask(a, a + W) % (1 << t + 1) != 0) {
                a += 1 << t;
            }
        }
    }

    cout << "! " << W - a << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}