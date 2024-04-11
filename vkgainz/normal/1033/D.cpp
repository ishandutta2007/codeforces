#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
const int MX = 1300001;
vector<bool> prime(MX, 1);

int main() {
    for(int i = 2; i < MX; i++) {
        if(prime[i]) {
            primes.push_back(i);
            for(long long j = i * 1LL * i; j < MX; j += i)
                prime[j] = false;
        }
    }
    int n; cin >> n;
    vector<long long> a(n);
    map<long long, int> f;
    vector<long long> doub;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if((long long) sqrt(a[i]) * 1LL * (long long) sqrt(a[i]) == a[i]) {
            bool quart = false;
            for(int x : primes) {
                if(x * 1LL * x == (long long) sqrt(a[i])) {
                    quart = true;
                    f[x] += 4;
                    break;
                }
            }
            if(!quart) f[(long long) sqrt(a[i])] += 2;
        }
        else {
            bool trip = false;
            for(int x : primes) {
                if(x * 1LL * x * 1LL * x == a[i]) {
                    trip = true;
                    f[x] += 3;
                    break;
                }
            }
            if(!trip)
                doub.push_back(a[i]);
        }
    }
    vector<pair<long long, long long>> fact((int) doub.size());
    for(int i = 0; i < (int) doub.size(); i++)
        fact[i] = {0, 0};
    for(int i = 0; i < (int) doub.size(); i++) {
        for(int j = i + 1; j < (int) doub.size(); j++) {
            if(doub[i] == doub[j]) continue;
            if(__gcd(doub[i], doub[j]) > 1) {
                long long p = __gcd(doub[i], doub[j]);
                fact[i] = {p, doub[i] / p};
                fact[j] = {p, doub[j] / p};
            }
        }
    }
    map<long long, int> freq;
    for(int i = 0; i < (int) fact.size(); i++) {
        if(fact[i].first && fact[i].second)
            ++f[fact[i].first], ++f[fact[i].second];
        else
            ++freq[doub[i]];
    }
    long long ans = 1LL;
    long long MOD = 998244353;
    for(auto [x, y] : freq) {
        bool found = false;
        for(auto [a, b] : f) {
            if(x % a == 0) {
                long long p = a, q = x / p;
                f[p] += y, f[q] += y;
                found = true;
                break;
            }
        }
        if(!found)
            ans *= (y + 1) * 1LL * (y + 1), ans %= MOD;

    }
    for(auto [a, b] : f) {
        ans *= (b + 1);
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}