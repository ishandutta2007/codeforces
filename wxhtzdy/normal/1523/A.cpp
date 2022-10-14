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

const int maxn = 1005;
char a[maxn], b[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        scanf("%s", a);
        while (m--) {
            bool cl = true;
            for (int i = 0; i < n; i++) {
                b[i] = a[i];
                int cnt = 0;
                if (i > 0 && a[i - 1] == '1') cnt++;
                if (i + 1 < n && a[i + 1] == '1') cnt++;
                if (cnt == 1 && b[i] != '1') b[i] = '1', cl = false;
            }
            if (cl) break;
            for (int i = 0; i < n; i++) a[i] = b[i];
        }
        for (int i = 0; i < n; i++) printf("%c", a[i]);
        printf("\n");
    }
    return 0;
}