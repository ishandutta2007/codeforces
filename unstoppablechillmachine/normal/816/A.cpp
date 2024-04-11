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

inline void error()
{
    cout << -1;
    exit(0);
}

int n, m, ans, cnt, sum, a, h;
vi Vec, arr;
string s;

bool check()
{
    stringstream str;
    string s, s1;
    str << h;
    str >> s;
    str.clear();
    str << m;
    str >> s1;

    if (s.size() < 2) s.ins(s.begin(), '0');
    if (s1.size() < 2) s1.ins(s1.begin(), '0');
    s += s1;
    return (s[0] == s[3] && s[1] == s[2]);
}

void inc()
{
    if (m < 59) m++;
    else
    {
        m = 0;
        h++;
        h %= 24;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> s;
    h = (s[0] - 48) * 10 + s[1] - 48;
    m = (s[3] - 48) * 10 + s[4] - 48;

    while(!check())
    {
        inc();
        ans++;
        //cout << h << " " << m << endl;
    }

    cout << ans;


    return 0;
}