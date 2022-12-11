#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
const long long linf = 1e16;
long long n, k;
string s[2];
long long f[2][N];
long long solve() {
    int com = 0;
    while (com < n && s[0][com] == s[1][com]) com++;
    for(int i = com; i < n; i++) s[0][i] = 'a' + 'b' - s[0][i];
    
    if (k == 1) return n;
    if (com == n) return n;


    long long ans = 2 * n - com;
    //f[0][com] = f[1][com] = 1;
    
    k -= 2;
    for(int i = com + 2; i <= n && k; i++)
        for(int j = 0; j <= 1; j++) {
            f[j][i] = f[j][i - 1] * 2 + s[j][i - 1] - 'a';
            long long use = min(k, f[j][i] - f[j][i - 1]);
            ans += use * (n - i + 1);
            k -= use;
        }
    return ans;
}
int main() {
    cin >> n >> k >> s[0] >> s[1];
    cout << solve();
}