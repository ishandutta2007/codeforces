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
const int maxn = 200005;
int n, z;
int a[maxn];
bool can(int x) {
    multiset<int> s;
    for (int i = x; i < n; i++) s.insert(a[i]);
    for (int i = 0; i < x; i++) {
        auto it = s.lower_bound(a[i] + z);
        if (it == s.end()) return false;
        s.erase(it);
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &z);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int bot = 1, top = n / 2, ans = 0;
    while (bot <= top) {
        int mid = bot + top >> 1;
        if (can(mid)) ans = mid, bot = mid + 1;
        else top = mid - 1;
    }
    printf("%d", ans);
    return 0;
}