#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];
#define SZ(X) (int)X.size();

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int f(int l, const string& a, const string& b)
{
    int sum = 0;
    for (int i = 0; i < l; ++i)
        sum += a[i] != b[i];
    return sum;
}

int main()
{ _
    int n, t; cin >> n >> t;
    string s[2]; cin >> s[0] >> s[1];

    string s3;
    for (int i = 0; i < n; ++i)
    {
        if (s[0][i] == s[1][i])
            s3.pb(s[0][i]);

        else
        {
            set<char> S = { 'a', 'b', 'c' };
            S.erase(s[0][i]);
            S.erase(s[1][i]);

            s3.pb(*S.begin());
        }
    }

    int x = f(n, s[0], s[1]);

    if (x > t)
    {
        bool w = 0;

        int c = 0;
        for (int i = 0; i < n && c < 2 * (x - t); ++i)
            if (s[0][i] != s[1][i])
            {
                s3[i] = s[w][i];
                c++;
                w = !w;
            }
    }

    if (x < t)
    {
        int c = 0;
        for (int i = 0; i < n && c < (t - x); ++i)
            if (s[0][i] == s[1][i])
            {
                s3[i] = 'b' + ((s[0][i] - 'a') % 10);
                c++;
            }
    }

    if (f(n, s[0], s3) != t || f(n, s[1], s3) != t)
    {
        cout << - 1 << endl;
        exit(0);
    }
    else
        cout << s3 << endl;

    exit(0);
}