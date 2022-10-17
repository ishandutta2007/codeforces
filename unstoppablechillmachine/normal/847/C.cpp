#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vll> vvll;
typedef long double ld;
typedef vector <ld> vld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef vector <bool> vbool;

#define add push_back
#define del pop_back
#define ins insert
#define ers erase
#define F first
#define S second
#define sqr(x) ((x) * (x))
#define pw(x) (1LL << (x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
mt19937 Random((int)time(0));
inline ll rnd(ll x) { return Random() % x; }
#define TASK ""

const ll INF = (ll)1e9 + 2017;
const ll MOD = (ll)1e9 + 7;
const ld EPS = 1e-10;
const ld PI = acos(-1.0);

void source()
{
    ll n, k;
    cin >> n >> k;
    if (n * (n - 1) / 2 < k)
    {
        cout << "Impossible";
        return;
    }
    string ans;
    ll b = 0;
    for (int i = 0; i < n * 2; i++)
    {
        if (k - b >= 0)
        {
            k -= b;
            b++;
            ans.add('(');
        }
        else
        {
            b--;
            ans.add(')');
        }
    }
    if (k > 0)
    {
        ans = "Impossible";
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(10);
#ifdef _F1A4X_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    source();
#ifdef _F1A4X_
    cout << endl << endl << "\t" << (ld)clock() / CLOCKS_PER_SEC << " sec" << endl;
#endif
}