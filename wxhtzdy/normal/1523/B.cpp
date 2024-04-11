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

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        printf("%d\n", (n / 2) * 6);
        for (int i = 1; i <= n; i += 2) {
            printf("1 %d %d\n", i, i + 1);
            printf("2 %d %d\n", i, i + 1);
            printf("1 %d %d\n", i, i + 1);
            printf("2 %d %d\n", i, i + 1);
            printf("1 %d %d\n", i, i + 1);
            printf("2 %d %d\n", i, i + 1);
        }
    }
    return 0;
}