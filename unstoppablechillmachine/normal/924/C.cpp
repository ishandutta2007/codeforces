#include <bits/stdc++.h>
#include <random>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <ll, ll> pii;
typedef pair <ll, ll> pll;

#define add push_back
#define del pop_back
#define ins insert
#define ers  erase
#define F first
#define S second
#define int ll
#define _ inline
ll sqr(ll x) { return x * x; }
#define pw(x) (1LL << (x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem(x, val) memset(x, val, sizeof(x))
_ ll gcd(ll a, ll b) { while (b) { a %= b, swap(a, b); } return a; }
_ ll lcm(ll a, ll b) { return a * b / max(1LL, gcd(a, b)); }
mt19937 Random((int)time(0));
_ ll rnd(ll x) { return Random() % x; }

const ll INF = (ll)1e9 + 2017;
const ll MOD = (ll)1e9 + 7;
const ld EPS = 1e-10;
const ld PI = acos(-1.0);

const int N = 1e5 + 10;
int arr[N];
multiset <ll> st;

void $main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        st.ins(-(arr[i] - i));
    }
    int kol = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        bool t = 1;
        ll res = -(*st.begin());
        if (kol - i < res + 1) {
            t = 0;
        }
        kol += (t ^ 1);
        ans += kol - arr[i] - 1;
        st.ers(st.find(-(arr[i] - i)));
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(10);
#ifdef flaax
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    $main();
#ifdef flaax
    cout << endl;
    cerr << endl << "\t" << fixed << setprecision(10) << (ld)clock() / CLOCKS_PER_SEC << " sec" << endl;
#endif
}