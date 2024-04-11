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
const int maxn = 100050;
int a[maxn];
int main() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] - a[i] > c) break;
        ans++;
    }
    cout << ans;
    return 0;
}