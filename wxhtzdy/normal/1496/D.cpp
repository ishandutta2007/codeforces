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
const int maxn = 100005;
int n, p[maxn];
int l[maxn], r[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 || p[i] < p[i - 1]) l[i] = 1;
        else l[i] = l[i - 1] + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || p[i] < p[i + 1]) r[i] = 1;
        else r[i] = r[i + 1] + 1;
    }
    pi cur = {0, 1};
    for (int i = 0; i < n; i++) {
        if (l[i] > cur.fi) cur = {l[i], 1};
        else if (l[i] == cur.fi) cur.se++;
    }
    for (int i = 0; i < n; i++) {
        if (r[i] > cur.fi) cur = {r[i], 1};
        else if (r[i] == cur.fi) cur.se++;
    }
    if (cur.se != 2 || cur.fi % 2 == 0) return 0 * printf("0");
    for (int i = 0; i < n; i++) {
        if (l[i] == r[i] && l[i] == cur.fi) {
            printf("1");
            return 0;
        }
    }
    printf("0");
    return 0;
}