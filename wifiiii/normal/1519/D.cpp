#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // a[1], a[2], ... a[i], ... a[j] ... a[n]
    // b[1], b[2], ... b[i], ... b[j] ... b[n]
    // a[1], a[2], ... a[j], ... a[i] ... a[n]
    // a[n], a[n-1], ...                  a[1]
    // J - I = b[i](a[j]-a[i]) + b[i+1](a[j-1]-a[i+1]) + ... + b[j](a[i]-a[j])
    //       = (b[i]a[j] + b[i+1]a[j-1] + ... + b[j]a[i]) - (a[i]b[i] + ... + a[j]b[j])
    //       =
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    vector<ll> ra = a;
    reverse(ra.begin(), ra.end());
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += 1ll * a[i] * b[i];
    }
    ll ans = sum;
    // a[0] a[1]   a[2]   ... a[n-1] a[n]
    //               b[0] b[1]   b[2]   ... b[n-1] b[n]
    // a[n] a[n-1] a[n-2] ... a[1]   a[0]
    for(int i = 0; i < n; ++i) {
        ll cur = 0;
        for(int j = 0; j <= i; ++j) cur += b[j] * (a[i - j] - a[j]);
        ans = max(ans, sum + cur);
        int l = 0, r = i;
        while(l < r) {
            cur = cur + b[l] * a[l] + b[r] * a[r] - b[l] * a[r] - b[r] * a[l];
            ans = max(ans, sum + cur);
            ++l, --r;
        }
    }
    // a[0] a[1]   a[2]   ... a[n-1]
    // b[0] b[1]   b[2]   ... b[n-1]
    //             a[n] a[n-1] a[n-2] ... a[1]   a[0]
    for(int i = n; i < n + n; ++i) {
        ll cur = 0;
        for(int j = i - n + 1; j < n; ++j) {
            cur += b[j] * (a[i - j] - a[j]);
        }
        ans = max(ans, sum + cur);
        int l = i - n + 1, r = n - 1;
        while(l < r) {
            cur = cur + b[l] * a[l] + b[r] * a[r] - b[l] * a[r] - b[r] * a[l];
            ans = max(ans, sum + cur);
            ++l, --r;
        }
    }
    cout << ans << '\n';
}