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
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int a = 0; a <= 1000; a++) {
        for (int b = 0; b <= 1000; b++) {
            if (a * a + b == n && a + b * b == m) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}