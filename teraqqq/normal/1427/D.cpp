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

void solve() {
    int n; cin >> n;
    vi a(n), b(n+1); for(int& i : a) cin >> i;

    vector<vi> ops;

    for(; ;) {
        for(int j = 0; j < n; ++j)
            b[a[j]] = j;
        bool done = false;

        //for(int i : a) cout << i << ' '; cout << endl;

        for(int j = 1; j < n && !done; ++j) {
            if(b[j+1] < b[j]) {
                int u = j;
                while(u != 1 && b[u-1] + 1 == b[u]) --u;

                int A = b[j+1];
                int B = b[u] - b[j+1];
                int C = b[j] - b[u] + 1;
                int D = n - A - B - C;
                ops.pb(vi());
                if(A) ops.back().pb(A);
                if(B) ops.back().pb(B);
                if(C) ops.back().pb(C);
                if(D) ops.back().pb(D);

                vi vA(a.begin(), a.begin() + A),
                   vB(a.begin() + A, a.begin() + A + B),
                   vC(a.begin() + A + B, a.begin() + A + B + C),
                   vD(a.begin() + A + B + C, a.end());
                a.clear();

                a.insert(a.end(), vD.begin(), vD.end());
                a.insert(a.end(), vC.begin(), vC.end());
                a.insert(a.end(), vB.begin(), vB.end());
                a.insert(a.end(), vA.begin(), vA.end());
                done = true;
            }
        }
        if(!done) break;
    }

    cout << ops.size() << '\n';
    for(vi v : ops) {
        cout << v.size() << ' ';
        for(int i : v) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}