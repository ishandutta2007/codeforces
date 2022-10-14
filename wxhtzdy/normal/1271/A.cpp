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
int a, b, c, d, e, f;
int main() {
    cin >> a >> b >> c >> d >> e >> f;
    int ans = 0;
    for (int i = 0; i <= min(a, d); i++) {
        ans = max(ans, i * e + min({b, c, d - i}) * f);
    }
    cout << ans;
    return 0;
}