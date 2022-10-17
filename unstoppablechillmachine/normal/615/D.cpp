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
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

map<ll, ll> mp;
bool t, tr;
ll n, a;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    forn(i, n)
    {
        cin >> a;
        mp[a]++;
    }

    for(auto i : mp)
    {
        if ((i.sec) % 2) t = true;
    }
    n = 1;
    if (!t)
    {
        for(auto i : mp)
        {
            forn(j, (i.sec) / 2)
            {
                n  = (n * (i.f)) % MOD;
            }
        }
        //cout << n << endl;
        for(auto i : mp)
        {
            a = n;
            forn(j, i.sec)
            {
                n = (n * a) % MOD;
            }
        }
        cout << n;
    }
    else
    {
        for(auto i : mp)
        {
            forn(j, i.sec)
            {
                n = (n * (i.f)) % MOD;
            }
        }
        //cout << n << endl;
        for(auto i : mp)
        {
            if ((i.sec + 1) % 2 == 0 && !tr)
            {
                tr = true;
                a = n;
                forn(j, (i.sec + 1) / 2 - 1)
                {
                    n = (n * a) % MOD;
                }
            }
            else
            {
                a = n;
                forn(j, i.sec)
                {
                    n = (n * a) % MOD;
                }
            }
            //cout << n << " " << i.sec + 1 << endl;
        }
        cout << n;
    }
    return 0;
}