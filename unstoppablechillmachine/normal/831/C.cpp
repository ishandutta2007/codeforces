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
const int MAXN = 2e7 + 10;
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

set<int> st;
int n, k, arr[MAXN], arr2[MAXN], pref[MAXN], ans;
unordered_map<int, bool> used;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    forn(i, n)
    {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }
    forn(i, k)
    {
        cin >> arr2[i];
    }
    int a = arr2[1];
    forn(i, n)
    {
        int now = a - pref[i];
        //cout << now << endl;
        if (used[now])
        {
            continue;
        }
        used[now] = true;
        st.clear();
        forn(j, k)
        {
            st.ins(arr2[j]);
        }
        forn(j, n)
        {
            now += arr[j];
            if (st.find(now) != st.end())
            {
                st.ers(now);
            }
        }
        if (st.empty())
        {
            //cout << now << endl;
            ans++;
        }
    }
    cout << ans;
    return 0;
}