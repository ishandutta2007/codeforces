#include <bits/stdc++.h>
using namespace std;

const int maxn = 32000 + 10;
vector<int> prime;
bool v[maxn];

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if(!v[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < maxn; ++j) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    // sieve();
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; while (n--) {
        int a, b; cin >> a >> b;
        if (a == b && b == 1) { cout << "Yes" << endl; continue; }
        bool ans = true;
        long long t= (long long)a * (long long)b;
        long long c = (long long)cbrtl(t);
        if (c * c * c == t) {
            int g = __gcd(a, b);
            if (g % c == 0) ans = true;
            else ans = false;
        }
        else ans = false;
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}