#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxp = 32000;
int a[maxn];
bool v[maxp];
vector<int> prime;
map<int, int> mask, sg;
set<int> has;

void sieve() {
    for (int i = 2; i < maxp; ++i) {
        if (!v[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < maxp; ++j) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int go(int m) {
    if (m == 0) return 0;
    if (sg.count(m)) return sg[m];
    bitset<maxn> v;
    for (int k = 1; k <= 30; ++k) if (m >> (k - 1)) {
        int s = go((m >> k) | (m & ((1 << (k - 1)) - 1)));
        if (s < maxn) v[s] = true;
    }
    for (int i = 0; i < maxn; ++i) {
        if (!v[i]) return sg[m] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int n; cin >> n;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int t = a[i];
        for (int j : prime) {
            int c = 0;
            while (t % j == 0) t /= j, ++c;
            if (c) mask[j] |= (1 << (c - 1));
        }
        if (t > 1 && !has.count(t)) x ^= 1, has.insert(t);
    }
    for (int j : prime) x ^= go(mask[j]);
    cout << (x ? "Mojtaba" : "Arpa") << endl;
    return 0;
}