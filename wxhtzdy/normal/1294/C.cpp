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
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a = -1, b = -1, c = -1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                a = i;
                break;
            }
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0 && i != a) {
                n /= i;
                b = i;
                break;
            }
        }
        c = n;
        if (min({a, b, c}) <= 1 || a == c || b == c) {
            printf("NO\n");
        } else {
            printf("YES\n");
            printf("%d %d %d\n", a, b, c);
        }
    }
}