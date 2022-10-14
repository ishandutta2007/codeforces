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
const int maxn = 1000005;
int n, k;
int a[maxn], b[maxn];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        bool kk1 = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            kk1 |= (a[i] == k);
        }
        bool kk2 = (n == 1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (j - i > 2) break;
                if (a[i] >= k && a[j] >= k) kk2 = true;
            }
        }
        if (kk1 && kk2) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}