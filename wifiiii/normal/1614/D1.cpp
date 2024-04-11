#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e6 + 6;
int cnt[N], sum[N];
ll dp[N];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i], cnt[a[i]] += 1;
    for(int i = 1; i < N; ++i) {
        for(int j = i; j < N; j += i) {
            sum[i] += cnt[j];
        }
    }
    for(int i = N - 1; i >= 1; --i) {
        dp[i] = 1ll * sum[i] * i;
        for(int j = i + i; j < N; j += i) {
            dp[i] = max(dp[i], dp[j] + 1ll * (sum[i] - sum[j]) * i);
        }
    }
    cout << dp[1] << '\n';
}