#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
 
using namespace std;
 
long long getMod(string s, long long MOD) {
    long long pow = 1LL;
    long long ans = 0LL;
    for (int i = s.length() - 1; i >= 0; i--)  {
        ans += (s[i] - '0') * pow % MOD;
        pow *= 10;
        pow %= MOD;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    return ans;
}

string minOne(string s) {
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] - '0' > 0) {
            s[i] = s[i] -  1;
            for (int j = i + 1; j < s.length(); j++) {
                s[j] = '9';
            }
            break;
        }
    }
    return s;
}

long long tpow[100001];

int main() {
    string b, n; 
    cin >> b >> n;
    long long c; cin >> c;
    n = minOne(n);
    long long x = getMod(b, c);
    long long ans = x - 1;
    long long tmp = x;
    for (int i = n.length() - 1; i >= 0; i--)  {
        int curr = n[i] - '0';
        for (int j = 0; j < curr; j++) {
            ans *= tmp;
            ans %= c;
        }
        long long nxt = 1LL;
        for (int j = 0; j < 10; j++) {
            nxt = nxt * tmp;
            nxt %= c;
        }
        tmp = nxt;
    }
    if (ans < 0) ans += c;
    if (ans == 0) cout << c << "\n";
    else cout << ans << "\n";
   
}