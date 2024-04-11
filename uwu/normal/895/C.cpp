#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1, MA = 71;

int a[MN], mp[MN];
ll dp[(1 << 19)], lst[(1 << 19)], cnt[MA], comb[MA][2];
bool prime[MN];
vector<int> primes;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ms(prime, 1); prime[0] = prime[1] = 0;
    for (int i = 2; i < MA; ++i){
        if (!prime[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j < MA; j += i) prime[j] = 0;
    }
    for (int i = 1; i < MA; ++i){
        for (int j = 0; j < primes.size(); ++j){
            int x = i;
            while (x % primes[j] == 0) mp[i] ^= 1 << j, x /= primes[j];
        }
    }
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i < MA; ++i){
        comb[i][0] = 1;
        for (int j = 1; j <= cnt[i]; ++j){
            comb[i][0] = (comb[i][0] + comb[i][1]) % mod;
            comb[i][1] = comb[i][0];
        }
    }
    dp[0] = 1;
    for (int i = 1; i < MA; ++i){
        swap(lst, dp);
        for (int j = 0; j < (1 << primes.size()); ++j){
            dp[j] = (lst[j] * comb[i][0] + lst[j ^ mp[i]] * comb[i][1]) % mod;
        }
    }
    cout << (dp[0] - 1 + mod) % mod << '\n';
}