#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;

void print(int st, int n) {
    printf("%d ", st + n - 1);
    for (int i = 0; i < n - 1; i++) printf("%d ", st + i);
}

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a > b) swap(a, b);
    for (int i = 0; i <= n; i++) {
        if (a * i > n) break;
        if ((n - i * a) % b != 0) continue;
        int x = i, y = (n - i * a) / b, j = 1;
        while (x--) {
            print(j, a);
            j += a;
        }
        while (y--) {
            print(j, b);
            j += b;
        }
        return 0;
    }
    printf("-1");
    return 0;
}