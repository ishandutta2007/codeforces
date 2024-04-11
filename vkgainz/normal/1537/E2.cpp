#include <bits/stdc++.h>
using namespace std;

const int p = 89;
long long invL;
long long MOD = 2000004043;
vector<long long> power(1000001), invpow(1000001), inver(500001);
vector<long long> hashS;

long long inv(long long b, long long p = MOD - 2) {
    if(p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if(p % 2) x = x * b % MOD;
    return x;
}

long long get_rep(long long st, int len, int rep) {
    if(rep == 0) return 0LL;
    return (power[len * rep] - 1) % MOD * 1LL * inver[len] % MOD * st % MOD;
}

long long get_hash(int idx, int len, int n) {
    int rep = len / (idx);
    long long st = hashS[idx];
    long long x = get_rep(st, idx, rep) % MOD;
    int left = len % idx;
    long long y = hashS[left] % MOD;
    y *= power[rep * idx];
    y %= MOD;
    return (x + y) % MOD;
}
int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    power[0] = 1LL;
    for(int i = 1; i <= 1000000; i++) {
        power[i] = power[i - 1] * 1LL * p % MOD;
    }
    for(int i = 1; i <= 500000; i++) {
        inver[i] = inv(power[i] - 1);
    }
    invpow.back() = inv(power.back());
    for(int i = 999999; i >= 0; i--) {
        invpow[i] = invpow[i + 1] * 1LL * (i + 1) % MOD;
    }
    hashS.resize(n + 1);
    hashS[0] = 0LL; 
    for(int i = 1; i <= n; i++) {
        hashS[i] = (hashS[i - 1] + power[i] * 1LL * (s[i - 1] - 'a')) % MOD;
    }
 	int bst = 1;
     for(int i = 1; i <= n; i++) {
         if(get_hash(bst, k, n) == get_hash(i, k, n)) continue;
          //cout << i << " " << bst << "\n";
          int lo = 0, hi = k;
          for(int j = 0; j < 25; j++) {
              int mid = (lo + hi) / 2;
              long long hashPref, hashCmp;
              hashPref = get_hash(bst, mid, n);
              hashCmp = get_hash(i, mid, n);
              if(hashPref < 0) hashPref += MOD;
              if(hashCmp < 0) hashCmp += MOD;
              if(hashPref == hashCmp) {
                  lo = mid + 1;
              }
              else {
                  hi = mid;
              }
          }
          //compare the two
          if(s[(lo - 1) % i] < s[(lo - 1) % bst])
              bst = i;
      }
      string take = s.substr(0, bst);

    while(take.length() < k) {
          take = take + take;
      }
      cout << take.substr(0, k) << "\n";       
}