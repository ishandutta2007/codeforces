#include <bits/stdc++.h>

using namespace std;

vector<int> f(60300005);

int main() {
    string s; cin >> s;
    int n = (int) s.length();
    const int SQRT = 300;
    long long ans = 0LL;
    for (int ratio = 1; ratio <= SQRT; ratio++) {
        int curr = 0;
        ++f[curr + n];
        for (int j = 1; j <= n; j++) {
            if (s[j - 1] == '1') curr += (ratio - 1);
            else curr--;
            ans += f[curr + n]++;
        }
        curr = 0;
        --f[curr + n];
        for (int j = 1; j <= n; j++) {
            if (s[j - 1] == '1') curr += ratio - 1;
            else curr--;
            --f[curr + n];
        }
    }
    vector<int> pos;
    pos.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') pos.push_back(i);
        int st = (int) pos.size();
        for (int x = 1; x <= n / SQRT; x++) {
            --st;
            if (st == 0) break;
            int a = i - pos[st] + 1, b = i - pos[st - 1];
            int fir = (a + x - 1) / x, lst = b / x;
            ans += max(0, lst - max(fir, SQRT + 1) + 1);
        }
    }
    cout << ans << "\n";
}