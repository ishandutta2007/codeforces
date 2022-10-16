#include <bits/stdc++.h>

#define F first
#define S second
#define rsz resize
#define pb push_back

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = 4*atan((ld)1);

mt19937 rng;

void solve() {
    int n, m, k, a = 0; cin >> n >> m >> k;
    vector<string> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        for(int j = 0; j < m; ++j)
            if(v[i][j] == 'R') ++a;
    }

    int cx = 0, cy = 0;

    vector<char> alphabet;
    for(int i = 0; i < 10; ++i) alphabet.pb(i + '0');
    for(int i = 0; i < 26; ++i) alphabet.pb(i + 'a');
    for(int i = 0; i < 26; ++i) alphabet.pb(i + 'A');

    vector<vi> res(n, vi(m));
    for(int i = 0; i < k; ++i) {
        int t = i == k-1 ? INF : a/k + (a%k > i);
        while(t != 0 && cy < m) {
            res[cx][cy] = i, t -= v[cx][cy] == 'R';
            if(cy%2 == 0) { if(++cx == n) cx = n-1, ++cy; }
            else          { if(cx-- == 0) cx = 0,   ++cy; }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cout << alphabet[res[i][j]];
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    int q; for(cin >> q; q--; ) solve();
}