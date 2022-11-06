#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 1010;
int n, m;
int a[maxn][maxn];
char s[maxn];
int sum[maxn][maxn];
int tot;

int count(int a, int b, int c, int d) {
    return sum[a + 1][b + 1] - sum[a + 1][d] - sum[c][b + 1] + sum[c][d];
}

bool go(int x, int y, int i, int j, int cnt) {
    if (count(x + i - 1, y + j - 1, x , y) != i * j) return 0;
    //if (i * j == 8) cout<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<count(x + i - 1, y + j - 1, x , y)<<"\n";
    if (cnt == tot) {
        //cout<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<count(2, 3, 1, 0)<<"\n";
        //cout<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<cnt<<"\n";
        return 1;
    }
    if (x >= n || y >= m) return 0;
    bool res = 0;
    if (count(x + i, y + j - 1, x + 1, y) == i * j && count(x + i - 1, y + j, x, y + 1) != i * j) res |= go(x + 1, y, i, j, cnt + j);
    if (count(x + i - 1, y + j, x, y + 1) == i * j && count(x + i, y + j - 1, x + 1, y) != i * j) res |= go(x, y + 1, i, j, cnt + i);
    return res;
}

void solve() {
    ms(sum, 0); tot = 0;
    scanf("%d%d", &n, &m);
    FOR(i, 0, n) {
        scanf("%s", s);
        FOR(j, 0, m) tot += (a[i][j] = s[j] == 'X');
    }
    int u, v; FORd(i, n, 0) FORd(j, m, 0) if (a[i][j]) {u = i; v = j;}
    FOR(i, 1, n + 5) FOR(j, 1, m + 5) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i - 1][j - 1];
    //cout<<sum[3][4] - sum[2][0] - sum[1][3]; return;
    //cout<<count(2, 3, 1, 0); return;
    //cout<<count(1, 3, 0, 0); return;
    int ans = INT_MAX;
    FOR(i, 1, n + 1) FOR(j, 1, m + 1) if (go(u, v, i, j, i * j)) ans = min(ans, i * j);
    if (ans == INT_MAX) ans = -1;
    cout<<ans;
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