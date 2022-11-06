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

const int maxn = 110;
int n;
ld x[maxn], y[maxn], z[maxn];
ld ans[3];

ld distance(ld x1, ld y1, ld z1, ld x2, ld y2, ld z2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}

void solve() {
    //int T; scanf("%d", &T);
    //while (T--) {
        scanf("%d", &n);
        ans[0] = ans[1] = ans[2] = 0;
        ld lambda = 1;
        FOR(i, 0, n) cin>>x[i]>>y[i]>>z[i];
        FOR(i, 0, 100000) {
            ld dmax = INT_MIN; int imax;
            FOR(i, 0, n) {
                ld d = distance(ans[0], ans[1], ans[2], x[i], y[i], z[i]);
                if (dmax < d) {dmax = d; imax = i;}
            }
            ans[0] += lambda * (x[imax] - ans[0]);
            ans[1] += lambda * (y[imax] - ans[1]);
            ans[2] += lambda * (z[imax] - ans[2]);
            lambda *= 0.999;
        }
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        //cout<<int(-9.12)<<endl;
        //cout<<floor(ans[0] + 0.5)<<" "<<floor(ans[1] + 0.5)<<" "<<floor(ans[2] + 0.5);
        //if (T > 0) cout<<endl;
    //}
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