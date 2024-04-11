#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cpx = complex<ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int amax = 3e5, magic = 800;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> small(magic), cntsmall(magic), addcnt(magic), sub(amax + 2), addsub(amax + 2);
    vector<cpx> prefsum(amax + 2), add(amax + 2);
    auto query = [&](int l, int r) {
        return prefsum[r] - (l ? prefsum[l - 1] : 0);
    };
    ll p = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        //a[i] = 1 + rng() % amax;

        // update stuff
        add[a[i]] += cpx(1, a[i]);
        for (int x = 1; x < magic; ++x) {
            small[x] += a[i] % x;
        }
        if (a[i] < magic) {
            ++addcnt[a[i]];
        }
        else {
            for (int x = a[i]; x <= amax; x += a[i]) {
                addsub[x] += a[i];
            }
        }
        int z = i - i % magic;
        // rebuild
        if (z == i) {
            fill(begin(prefsum), end(prefsum), 0);
            partial_sum(begin(add), end(add), begin(prefsum));
            fill(begin(sub), end(sub), 0);
            partial_sum(begin(addsub), end(addsub), begin(sub));
            cntsmall = addcnt;
        }

        // a[i] mod prev
        p -= sub[a[i]];
        for (int x = 1; x < magic; ++x) {
            p -= cntsmall[x] * (a[i] / x) * x;
        }
        p += 1LL * (z + 1) * a[i];
        // prev mod a[i]
        if (a[i] < magic) {
            p += small[a[i]];
        }
        else {
            for (int x = 0; x <= amax; x += a[i]) {
                cpx pt = query(x, min(amax, x + a[i] - 1));
                p += pt.imag() - x * pt.real();
            }
        }
        // left overs
        for (int j = i; j > z; --j) {
            // a[i] mod prev
            p += a[i] % a[j];
            // prev mod a[i]
            if (a[i] >= magic) p += a[j] % a[i];
        }
        cout << p << "\n "[i + 1 < n];
    }
    exit(0);
}