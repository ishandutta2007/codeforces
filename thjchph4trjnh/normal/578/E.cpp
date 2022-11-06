#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
char s[maxn];
set<int> S[2];

void solve() {
    scanf("%s", s);
    int len = strlen(s);
    FOR(i, 0, len) if (s[i] == 'L') S[0].insert(i); else S[1].insert(i);
    vi ans; int cnt = 0; bool flag;
    if (sz(S[0]) > sz(S[1])) flag = 0;
    else if (sz(S[0]) < sz(S[1])) flag = 1;
    else if (*S[0].begin() < *S[1].begin()) flag = 0;
    else flag = 1;
    int cur = -1;
    while (sz(S[0]) + sz(S[1])) {
        set<int>::iterator it = S[flag].upper_bound(cur);
        if (it == S[flag].end()) {cnt++; it = S[flag].begin();}
        int k = *it;
        if (S[flag ^ 1].upper_bound(*it) == S[flag ^ 1].end())
        {
            int p = *S[flag ^ 1].begin();
            int q = *S[flag].begin();
            if (q < p) {
                if (k != q) cnt++;
                k = q;
            }
        }
        ans.push_back(k); cur = k; S[flag].erase(k); flag ^= 1;
    }
    printf("%d\n", cnt);
    FOR(i, 0, sz(ans)) printf("%d ", ans[i] + 1);
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}