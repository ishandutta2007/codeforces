#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int merge(int lhs, int rhs, char ch) {
    if (ch == '0') return rhs;
    else if (ch == '1') return lhs;
    else return lhs + rhs;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    string s;
    cin >> s;
    s.push_back('*');
    reverse(all(s));

    int n = 1 << k;
    vector<int> st(2 * n);
    fill(n + all(st), 1);
    for (int p = n - 1; p; --p) {
        st[p] = merge(st[p << 1], st[p << 1 | 1], s[p]);
    }

    int q;
    cin >> q;

    for (int z = 0; z < q; ++z) {
        int p;
        cin >> p;
        p = n - p;
        cin >> s[p];
        for (; p; p >>= 1) {
            st[p] = merge(st[p << 1], st[p << 1 | 1], s[p]);
        }
        cout << st[1] << endl;
    }

    exit(0);
}