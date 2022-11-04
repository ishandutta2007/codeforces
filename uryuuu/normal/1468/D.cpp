#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
typedef tuple<int, int, int> mkgroups;
const ll mod = 1e9 + 7;
const int N = 1e6 + 100;
int T;
int n, m;
ll a, b;
ll s[N];

int check(int x, ll up) {
    for (int i = 1; i <= x; i++) {
        if (1ll * (s[i] + (x - i + 1)) > up)return 0;
    }
    return 1;
}

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d%d%lld%lld", &n, &m, &a, &b);
        for (int i = 1; i <= m; i++)scanf("%lld", &s[i]);
        sort(s + 1, s + m + 1);
        ll len = 1ll * abs(a - b);
        if (a < b)len += a - 1;
        else len += n - a;
        int pos = lower_bound(s + 1, s + m + 1, len - 1) - s;
        if (s[pos] > len - 1 && pos <= m)pos--;
        if (pos > m)pos = m;
        pos = min(1ll * pos, abs(a - b) - 1);
        int ans = pos;
        if (pos > 0) {
            int l = 1, r = pos, mid;
            while (l <= r) {
                mid = l + r >> 1;
                if (check(mid, len))l = mid + 1, ans = mid;
                else r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}