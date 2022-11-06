#include <bits/stdc++.h>

#define Pi acos(-1.)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define fi first
#define se second
#define FILE "474"
#define standart 1

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 1e9 + 322;
const ll LINF = 2e18 + 474;
const ll MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;


int n, k, ans = 1;
int a[MAXN];

void solve() {
    cin >> n >> k;
    int cur = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            ans = max(ans, cur);
            cur = 1;
        }
        else
            cur++;
    }
    ans = max(ans, cur);
    cout << ans;
}




int main() {
    if(!standart) {
        freopen(FILE".in", "r", stdin);
        freopen(FILE".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    setlocale(LC_ALL, "Russian");
    int T = 1; //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}