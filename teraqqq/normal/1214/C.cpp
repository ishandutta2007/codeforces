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

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

bool solve(int n, string s) {
    if (n % 2) return false;

    int h = 0;
    for (char c : s) {
        h += (c=='(') - (c==')');
        if (h < -1) return false;
    }
    if (h != 0) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    bool ok = solve(n, s);
    cout << (ok ? "YES" : "NO") << endl;
}