#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<bool> vb;

#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz size
#define rsz resize
#define fro for
#define itn int
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int MAXN = 310 * 310;
const int SMAXN = 310;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

inline int rst(pii a, pii b)
{
    return abs(a.f - b.f) + abs(a.sec - b.sec);
}

int n, m, k, a, sum, cnt[MAXN], from, to, v, len, dist[MAXN], ans = INF;
vector<vpii> Vec;
vector<vpii> arr;
set<pii> st;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    forn(i, 5)
    {
        cin >> a;
        cnt[a]++;
        sum += a;
    }

    int max1 = 0;
    for(int i = 100; i >= 0; i--)
    {
        if (cnt[i] >= 3) max1 = max(max1, i * 3);
        else if (cnt[i] >= 2) max1 = max(max1, i * 2);
    }
    cout << sum - max1;
    return 0;
}