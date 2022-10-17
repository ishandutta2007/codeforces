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

int a, b, c;
map<char, int> mp;
char ch1, ch2;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    mp['v'] = 1;
    mp['<'] = 2;
    mp['^'] = 3;
    mp['>'] = 4;
    cin >> ch1 >> ch2;
    a = mp[ch1];
    b = mp[ch2];
    cin >> c;
    c %= 4;
    if (b < a) b += 4;
    if (c == 0)
    {
        if (b == a)
        {
            cout << "undefined";
        }
        else if (b - a == c)
        {
            cout << "cw";
        }
        else
        {
            cout << "ccw";
        }
    }
    else if (c == 2)
    {
        if (b - a == 2)
        {
            cout << "undefined";
        }
        else if (b - a == c)
        {
            cout << "cw";
        }
        else
        {
            cout << "ccw";
        }
    }
    else
    {
        if (b - a == c)
        {
            cout << "cw";
        }
        else
        {
            cout << "ccw";
        }
    }
    return 0;
}