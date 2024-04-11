#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1000000000;
ll const BINF = 1000000000000000000;
int const MAXN = 100;
ld const EPS = 1e-13;

#define f first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mk make_pair
#define fro for
#define itn int
#define forn(i, n) for (int i = 1; i <= n; i++)
#define fore(i, n) for (int i = 0; i < n; i++)

int n, cnt, ans = INF, kol;
bool t;
char ch;
string s[MAXN], s1;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    forn(i, n) cin >> s[i];
    forn(i, n)
    {
        cnt = 0;
        t = true;
        forn(j, n)
        {
            s1 = s[j];
            kol = 0;
            while (s1 != s[i] && kol <= s1.size())
            {
                cnt++;
                kol++;
                ch = s1[0];
                s1.erase(s1.begin());
                s1 = s1 + ch;
            }
            if (kol > s1.size()) t = false;
        }
        if (t) ans = min(ans, cnt);
    }

    if (ans >= INF) cout << -1;
    else cout << ans;

    return 0;
}