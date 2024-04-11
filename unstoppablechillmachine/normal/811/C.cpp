/*














*/
/*
  !










*/
/*

















*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9;
ll const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-6;

#define f first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mk make_pair
#define fro for
#define itn int
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

pii arr[5010];
int n, a[5010], xx[5010][5010], dp[5010], ans, pos[5010], l[5010], lf, rf;
vector<vector<pii> > Vec(5010), tr(5010);

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    for(int i = 0; i <= 5000; i++)
    {
        arr[i].f = -1;
        arr[i].sec = -1;
    }

    cin >> n;
    forn(i, n)
    {
        cin >> a[i];
        if (arr[a[i]].f == -1) arr[a[i]].f = i;
        arr[a[i]].sec = i;
    }

    for(int i = 0; i <= 5000; i++)
    {
        pos[i] = -1;
    }

    forn(i, n)
    {
        l[i] = pos[a[i]];
        pos[a[i]] = i;
    }

    forn(i, n)
    {
        xx[i][i] = a[i];
        for(int j = i + 1; j <= n; j++)
        {
            if (l[j] < i) xx[i][j] = (xx[i][j - 1] ^ a[j]);
            else xx[i][j] = xx[i][j - 1];
        }
    }

    forn(i, n)
    {
        tr[i].resize(n - i + 10);
        lf = arr[a[i]].f;
        rf = arr[a[i]].sec;
        tr[i][0] = mk(lf, rf);
        for(int j = i + 1; j <= n; j++)
        {
            lf = min(lf, arr[a[j]].f);
            rf = max(rf, arr[a[j]].sec);
            tr[i][j - i] = mk(lf, rf);
            //if (i == 14 && j == 100) cout << lf << " " << rf << endl;
        }
    }

    for(int i = 0; i <= 5000; i++)
    {
        if (arr[i].f != -1)
        {
            lf = tr[arr[i].f][arr[i].sec - arr[i].f].f;
            rf = tr[arr[i].f][arr[i].sec - arr[i].f].sec;
            while (tr[tr[lf][rf - lf].f][tr[lf][rf - lf].sec - tr[lf][rf - lf].f].f != lf || tr[tr[lf][rf - lf].f][tr[lf][rf - lf].sec - tr[lf][rf - lf].f].sec != rf)
            {
                lf = tr[tr[lf][rf - lf].f][tr[lf][rf - lf].sec - tr[lf][rf - lf].f].f;
                rf = tr[tr[lf][rf - lf].f][tr[lf][rf - lf].sec - tr[lf][rf - lf].f].sec;
            }
            Vec[rf].pb(mk(lf, xx[lf][rf]));
        }
    }

    dp[0] = 0;

    forn(i, n)
    {
        dp[i] = dp[i - 1];
        fore(j, Vec[i].size())
        {
            dp[i] = max(dp[i], dp[Vec[i][j].f - 1] + Vec[i][j].sec);
        }
        ans = max(ans, dp[i]);
    }



    cout << ans;

    return 0;
}