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
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

inline void error()
{
    cout << -1;
    exit(0);
}

int n, a[MAXN];
bool t1, t2;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    forn(i, n)
    {
        //cout << t1 << " " << t2 << endl;
        cin >> a[i];
        if (t2)
        {
            //cout << i << endl;
            if (a[i] >= a[i - 1])
            {
                cout << "NO";
                exit(0);
            }
        }
        else if (t1)
        {
            if (a[i] == a[i - 1]) continue;
            if (a[i] < a[i - 1]) t2 = true;
            if (a[i] > a[i - 1])
            {
                cout << "NO";
                exit(0);
            }
        }
        else
        {
            if (a[i] > a[i - 1]) continue;
            if (a[i] == a[i - 1])
            {
                t1 = true;
            }
            if (a[i] < a[i - 1]) t2 = true;

        }
    }

    cout << "YES";
    return 0;
}