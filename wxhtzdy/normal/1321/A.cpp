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

const int maxn=105;

int r[maxn], b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &r[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x += r[i] > b[i];
        y += r[i] < b[i];
    }
    if (x == 0) printf("-1");
    else printf("%d", (y + x) / x);
    return 0;
}