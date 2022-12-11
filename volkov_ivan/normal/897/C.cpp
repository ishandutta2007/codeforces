#include <iostream>

using namespace std;

const long long INF = 2e18, MAX_N = 1e5 + 5;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s = "z";
string s1 = "What are you doing while sending " + s;
string s2 = s + "? Are you busy? Will you send " + s;
string s3 = s + "?";
long long n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
long long dp[MAX_N + 1];

char rec(long long n, long long k) {
    if (n == 0) return f0[k - 1];
    if (k <= n1) {
        return s1[k - 1];
    }
    k -= n1;
    if (k <= dp[n - 1]) {
        return rec(n - 1, k);
    }
    k -= dp[n - 1];
    if (k <= n2) {
        return s2[k - 1];
    }
    k -= n2;
    if (k <= dp[n - 1]) {
        return rec(n - 1, k);
    }
    k -= dp[n - 1];
    return s3[k - 1];
}

int main() {
    long long q, n, k;
    char ans;
    dp[0] = f0.length();
    for (int i = 1; i <= MAX_N; i++) {
        if (dp[i - 1] == INF) dp[i] = INF;
        else {
            dp[i] = min(INF, dp[i - 1] * 2 + 68);
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> k;
        if (dp[n] < k) {
            cout << ".";
            continue;
        }
        ans = rec(n, k);
        if (ans == 'z') cout << '"';
        else cout << ans;
    }
    return 0;
}