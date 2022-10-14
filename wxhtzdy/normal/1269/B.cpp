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
const int maxn = 2005;
int n, m;
int a[maxn], b[maxn];
int c[maxn];
bool can(int x) {
    for (int i = 0; i < n; i++) {
        c[i] = (a[i] + x) % m;
    }
    sort(c, c + n);
    for (int i = 0; i < n; i++) {
        if (b[i] != c[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(b, b + n);
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int x = (b[i] - a[0] + m) % m;
        if (can(x)) chkmin(ans, x);
    }
    printf("%d", (ans == 1e9 ? -1 : ans));
    return 0;
}