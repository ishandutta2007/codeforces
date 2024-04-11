#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
ll merge_sort(vector<T>& v, vector<T>& aux, int l, int r) {
    if (r <= l) return 0LL;
    int m = l + (r - l) / 2;
    ll res = merge_sort(v, aux, l, m) + merge_sort(v, aux, m + 1, r);
    int x = l, y = m + 1, z = l;
    while (x <= m && y <= r) {
        aux[z++] = v[x] <= v[y] ? v[x++] : (res += m - x + 1, v[y++]);
    }
    while (x <= m) aux[z++] = v[x++];
    while (y <= r) aux[z++] = v[y++];
    while (l <= r) v[--z] = aux[r--];
    return res;
}

template<typename T>
ll inversions(vector<T> v) {
    static vector<T> aux;
    aux.resize(max(size(aux), size(v)));
    return merge_sort(v, aux, 0, (int)size(v) - 1);
}

string solve() {
    string a;
    cin >> a;
    int n = (int)size(a);

    ll cost = 0;
    string b = a;

    string C = "ANTO";
    sort(all(C));

    do {
        map<char, int> rk;
        for (int i = 0; i < 4; ++i) rk[C[i]] = i;

        vector<int> p(n);
        iota(all(p), 0);
        stable_sort(all(p), [&](int i, int j){ return rk[a[i]] < rk[a[j]]; });

        ll cur = inversions(p);
        if (cur > cost) {
            cost = cur;
            for (int i = 0; i < n; ++i) b[i] = a[p[i]];

            //debug(cost);
            //for (auto i : p) debug(i);
        }

    } while (next_permutation(all(C)));

    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) cout << solve() << endl;

    exit(0);
}