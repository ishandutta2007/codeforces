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
string s, s2;
bool t[50];
int cur = -1, m;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    fore(i, s.size())
    {
        int a = s[i] - 'a' + 1;
        t[a] = true;
    }

    cin >> s;
    fore(i, s.size())
    {
        if (s[i] == '*')
        {
            cur = i;
            break;
        }
    }
    cin >> m;
    forn(i, m)
    {
        cin >> s2;
        bool flag = true;
        if (cur == -1)
        {
            if (s.size() != s2.size())
            {
                cout << "NO" << endl;
                continue;
            }
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == s2[j] || (s[j] == '?') && t[s2[j] - 'a' + 1])
                {
                    continue;
                }
                flag = false;
            }
            if (!flag)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            if (s.size() - 1 > s2.size())
            {
                cout << "NO" << endl;
                continue;
            }
            for (int j = 0; j < cur; j++)
            {
                if (s[j] == s2[j] || (s[j] == '?') && t[s2[j] - 'a' + 1])
                {
                    continue;
                }
                flag = false;
            }
            int cnt = 0, p = s.size() - cur - 1;
            for (int j = s.size() - 1; j >= cur + 1; j--)
            {
                cnt++;
                if (s2.size() - cnt < 0)
                {
                    break;
                }
                if (s2[s2.size() - cnt] == s[j] || (s[j] == '?' && t[s2[s2.size() - cnt] - 'a' + 1]))
                {
                    continue;
                }
                flag = false;
            }
            for (int j = cur; j <= int(s2.size()) - cnt - 1; j++)
            {
                if (t[s2[j] - 'a' + 1])
                {
                    flag = false;
                }
            }
            if (!flag)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}