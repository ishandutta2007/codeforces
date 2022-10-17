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
const ld EPS = 1e-9;
const ld PI = acos(-1);

int n, ans, a, b;
string s;
map<char, int> mp;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> s;
    n = s.size();
    if (n % 2)
    {
        cout << -1;
        exit(0);
    }


    fore(i, s.size())
    {
        mp[s[i]]++;
    }

    a = mp['R'] + mp['L'];
    b = mp['D'] + mp['U'];
    if (b % 2)
    {
        if (mp['R'] > mp['L']) mp['R']--;
        else mp['L']--;
        if (mp['D'] > mp['U']) mp['U']++;
        else mp['D']++;
        ans = 1;
    }

    ans += (abs(mp['R'] - mp['L']) / 2);
    ans += (abs(mp['D'] - mp['U']) / 2);
    cout << ans;



    return 0;
}