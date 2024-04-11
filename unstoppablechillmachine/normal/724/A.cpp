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



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    map<string, int> mp;
    string s1, s2;
    int now, b;
    set<int> st;
    mp["monday"] = 1;
    mp["tuesday"] = 2;
    mp["wednesday"] = 3;
    mp["thursday"] = 4;
    mp["friday"] = 5;
    mp["saturday"] = 6;
    mp["sunday"] = 7;
    cin >> s1 >> s2;
    now = mp[s1] - 1;
    b = mp[s2];
    forn(i, 50)
    {
        now++;
        if (now == 8) now = 1;
        if (now == b) st.ins(i);
    }

    if (st.find(29) != st.end() || st.find(31) != st.end() || st.find(32) != st.end()) cout << "YES";
    else cout << "NO";

    return 0;
}