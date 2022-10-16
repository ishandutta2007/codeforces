#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;
using ll = long long;

const int N = 40, K = 10;

int n, k;
ll op[K];

bool is_okay(ll bits) {
    return (bits & (bits + 1)) == 0;
}

void print(ll mask, ll bits) {
    for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) cout << "?";
        else cout << ((bits >> i) & 1);
    }
}

bool brute(ll bits, ll mask, int pos) {
    // print(mask, bits);
    // cout << ", " << pos << endl;

    if (!mask && is_okay(bits)) return true;
    if (pos == k) return false;
    
    int max_bits = __builtin_popcountll((bits | mask) & op[pos]);
    int min_bits = __builtin_popcountll(bits & op[pos]);

    ll x = op[pos];
    for (int cnt = 0; cnt <= max_bits; ++cnt) {
        if (cnt >= min_bits) {
            
            if (!brute((bits | op[pos]) & ~x, mask & ~op[pos], pos + 1)) {
                /*
                cout << "ERROR, pos = " << pos << endl;
                print(0, bits);
                print(0, op[pos]);
                print(0, x);
                print(0, bits | op[pos]);
                */
                return false;
            }
        }
        x = x & x - 1;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    const ll ALL_BITS = (1ll << n) - 1;

    ll mor = 0;

    for (int i = 0; i < k; ++i) {
        int sz; cin >> sz;
        while (sz--) {
            int x; cin >> x;
            op[i] |= 1ll << x - 1;
            mor |= op[i];
        }
    }

    cout << (n == 1 || mor == ALL_BITS && brute(0, (1ll << n) - 1, 0) ? "ACCEPTED" : "REJECTED") << endl;
}