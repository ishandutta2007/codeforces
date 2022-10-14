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

int main() {
    int a, b;
    cin >> a >> b;
    vi ans(3);
    for (int i = 1; i <= 6; i++) {
        int x = abs(i - a), y = abs(i - b);
        if (x < y) ans[0]++;
        if (x == y) ans[1]++;
        if (x > y) ans[2]++;
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
    return 0;
}