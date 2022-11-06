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
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 1010;
int n, p;
char s[maxn];

bool check(int i, int val) {
    return (i < 1 || s[i - 1] != val) && (i < 2 || s[i - 2] != val);
}

void solve() {
    scanf("%d%d%s", &n, &p, s);
    if (p == 1) {
        printf("NO");
        return;
    }
    if (p == 2) {
        if (n == 1) {
            if (s[0] == 'a') printf("b");
            else printf("NO");
            return;
        }
        if (s[0] < s[1]) printf("ba");
        else printf("NO");
        return;
    }
    FORd(i, n, 0) {
        FOR(j, s[i] + 1, 'a' + p) if (check(i, j)) {
            s[i] = j;
            FOR(k, i + 1, n) FOR(l, 'a', 'a' + p) if (check(k, l)) {s[k] = l; break;}
            printf("%s", s);
            return;
        }
    }
    printf("NO");
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}