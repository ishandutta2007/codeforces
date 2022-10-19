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
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int ans = 2, n, len, a, b, a1, tri;
set<int> st;
bool tr, ta, tb;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    
    cin >> n >> len >> a >> b;
    forn(i, n)
    {
        cin >> a1;
        st.ins(a1);
    }

    for(auto i : st)
    {
        if (st.find(i + a) != st.end() || st.find(i - a) != st.end()) ta = true;
        if (st.find(i + b) != st.end() || st.find(i - b) != st.end()) tb = true;
        if ((st.find(i + b - a) != st.end() || st.find(i + b + a) != st.end()) && i + b <= len)
        {
            tr = true;
            tri = i + b;
        }
        if ((st.find(i - b + a) != st.end() || st.find(i - b - a) != st.end()) && i - b >= 0)
        {
            tr = true;
            tri = i - b;
        }
        if ((st.find(i - a + b) != st.end() || st.find(i - a - b) != st.end()) && i - a >= 0)
        {
            tr = true;
            tri = i - a;
        }
        if ((st.find(i - b + a) != st.end() || st.find(i + b + a) != st.end()) && i + a <= len)
        {
            tr = true;
            tri = i + a;
        }
    }

    if (ta && tb) cout << 0;
    else if (ta) cout << 1 << endl << b;
    else if (tb) cout << 1 << endl << a;
    else if (tr) cout << 1 << endl << tri;
    else cout << 2 << endl << a << " " << b;

    return 0;
}