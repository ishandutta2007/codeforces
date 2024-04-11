#include <bits/stdc++.h>
#include <cassert>

#define F first
#define S second

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string u = s;
        sort(u.begin(), u.end());

        int x = 0;
        for (int i = 0; i < n; ++i) if (u[i] != s[i]) x++;
        cout << x << '\n';
    }
}