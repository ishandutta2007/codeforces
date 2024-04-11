#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define add push_back
#define del pop_back
#define ins insert
#define ers erase
#define F first
#define S second
#define sqr(x) ((x) * (x))
#define pw(x) (1LL << (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937 Random((int)time(0));
inline ll rnd(ll x) { return Random() % x; }
#define TASK ""

const ll INF = (ll)1e9 + 2018;
const ll MOD = (ll)1e9 + 7;
const ld PI = acos(-1.0);

const int N = 1e5 + 10;
int arr[N];
ll dp[N];

ll intersect(int a, int b) {
    return max(0, a - b + 1);
}

void $main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!arr[i]) {
            dp[i] = min(i - 1, k) + min(n - i, k) + 1;
        } else {
            dp[i] = dp[arr[i]] + min(i - 1, k) + min(n - i, k) + 1 - intersect(min(n, arr[i] + k), max(1, i - k));
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(10);
#ifdef flaax
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    $main();
#ifdef flaax
    cout << endl;
    cerr << endl << "\t" << fixed << setprecision(10) << (ld)clock() / CLOCKS_PER_SEC << " sec" << endl;
#endif
}