#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

string s;
int n;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int x;
        string s;
        cin >> x >> s;         
        long long ans = s.length() + 1;
        s = "a" + s;


        for(int i = 1; i <= x; i++) {
            int time = s[i] - '0' - 1;
            ans = (ans + (ans - i - 1) * time) % MOD;

            int limit = s.length();
            while (time--) {
                for(int pos = i + 1; s.length() < x + 2 && pos < limit; pos++) {
                    s.push_back(s[pos]);
                }
            }
        }
        cout << (ans + 2 * MOD - 1) % MOD << '\n';
    }
}