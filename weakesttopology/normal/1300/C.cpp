#include "bits/stdc++.h"

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];
#define SZ(X) (int)X.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int N = 2 * 1e5;
int n;
int st[2 * N];

void build()
{
    for (int i = n - 1; i > 0; --i)
        st[i] = st[i << 1] | st[i << 1 | 1];
}

int query(int l, int r)
{
    int res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res |= st[l++];
        if (r & 1)
            res |= st[--r];
    }
    return res;
}

int main()
{ _
    cin >> n;
    vi a(n); READ(a);

    for (int i = 0; i < n; ++i)
        st[n + i] = a[i];

    build();

    int M = a[0] & ~query(1, n - 1);
    int index = 0;

    for (int i = 1; i < n; ++i)
    {
        int un = query(0, i - 1);
        if (i + 1 < n)
            un |= query(i + 1, n - 1);

        if (M < (a[i] & ~un))
        {
            M = a[i] & ~un;
            index = i;
        }
    }

    cout << a[index];
    for (int i = 0; i < n; ++i)
        if (i != index)
            cout << " " << a[i];
    cout << endl;

    exit(0);
}

/*
 * INT_MAX ~ 2 * 1e9 ~ 2^31 - 1
 * LLONG_MAX ~ 9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF ~ 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/