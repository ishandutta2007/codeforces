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
const int maxn = 200005;
int n, k;
string s, ans;
bool valid() {
    for (int i = 0; i < n; i++) {
        if (ans[i] > s[i]) return true;
        if (ans[i] < s[i]) return false;
    }
    return true;
}
int main() {
    cin >> n >> k >> s;
    ans = s;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            ans[j] = ans[i];
        }
    }
    if (valid()) {
        cout << n << "\n" << ans;
        return 0;
    }
    int x = 0;
    for (int i = 0; i < k; i++) {
        if (ans[i] != '9') {
            x = i;
        }
    }
    ans[x] = (char) (ans[x] + 1);
    for (int i = x + 1; i < k; i++) ans[i] = '0';
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            ans[j] = ans[i];
        }
    }
    assert(valid());
    cout << n << "\n" << ans;
    return 0;
}