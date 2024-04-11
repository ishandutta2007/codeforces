#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;
const int M = 1000000007;

multiset<int> multiples[N];
map<int, int> factors[N];
int ans = 1, n;

void add(int i, int j, int k) {
    int prv = (int) multiples[j].size() < n ? 0 : *multiples[j].begin();
    if (factors[i][j] > 0) {
        multiples[j].erase(multiples[j].find(factors[i][j]));
    }
    factors[i][j] += k;
    multiples[j].insert(factors[i][j]);
    int cur = (int) multiples[j].size() < n ? 0 : *multiples[j].begin();
    while (prv < cur) {
        ans = (long long) ans * j % M;
        ++prv;
    }
}

void update(int i, int x) {
    for (int j = 2; j * j <= x; ++j) {
        if (x % j == 0) {
            int p = 0;
            while (x % j == 0) {
                x /= j;
                ++p;
            }
            add(i, j, p);
        }
    }

    if (x > 1) {
        add(i, x, 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        update(i, x);
    }

    while (q--) {
        int i, x;
        cin >> i >> x;
        update(i, x);
        cout << ans << "\n";
    }
}