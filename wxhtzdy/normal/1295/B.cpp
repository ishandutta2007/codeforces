#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int sgn(int x) {
    if (x == 0) return 0;
    if (x < 0) return -1;
    if (x > 0) return 1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        string s;
        cin >> n >> x >> s;
        int cnt[2] = {0, 0};
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[cnt[0] - cnt[1]]++;
            cnt[(int) (s[i] - '0')]++;
        }
        if (cnt[0] == cnt[1]) {
            if (mp[x] > 0) cout << -1 << "\n";
            else cout << 0 << "\n";
            continue;
        }
        int ans = 0, bal = cnt[0] - cnt[1];
        cnt[0] = 0;
        cnt[1] = 0;
        for (int i = 0; i < n; i++) {
            if (abs(x - cnt[0] + cnt[1]) % abs(bal) == 0 && sgn(x - cnt[0] + cnt[1]) + sgn(bal) != 0) {
                ans++;
            }
            cnt[(int) (s[i] - '0')]++;
        }
        cout << ans << "\n";
    }
    return 0;
}