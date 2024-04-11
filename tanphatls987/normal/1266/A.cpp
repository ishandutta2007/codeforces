#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
const int MOD = 998244353;


int h[10];
string solve() {
    int sum = 0;
    for(int i = 0; i < 10; i++) sum += h[i] * i;
    if (sum % 3) return "cyan";

    if (h[0] == 0) return "cyan";
    h[0]--;

    for(int i = 0; i <= 8; i += 2) if (h[i]) return "red";
    return "cyan";
}
int main() {
    int test;
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        memset(h, 0, sizeof(h));
        for(auto ch : s) h[ch - '0']++;
        
        cout << solve() << '\n';
    }
}