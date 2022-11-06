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

const int maxn = 100010;
int n, k;
int a[maxn];
int cnt[10];

void solve() {
    scanf("%d%d", &n, &k);
    int ans = 0;
    FOR(i, 0, n) {
        scanf("%d", a + i);
        ans += a[i] / 10;
        cnt[a[i] % 10]++;
    }
    FORd(i, 10, 1) {
        int d = min(cnt[i], k / (10 - i));
        ans += d;
        k -= (10 - i) * d;
    }
    ans += k / 10;
    ans = min(ans, 10 * n);
    printf("%d", ans);
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