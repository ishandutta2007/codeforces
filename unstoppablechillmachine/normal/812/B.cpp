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

int const INF = 1e9 + 10;
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

int n, m, r[1001], l[1001], cur, cur1, ans = INF, sum, maxi = 1;
char ch;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m;
    forn(i, n) l[i] = INF;
    forn(i, n)
    forn(j, m + 2)
    {
        cin >> ch;
        if (ch == '1')
        {
            l[n - i + 1] = min(l[n - i + 1], j);
            r[n - i + 1] = max(r[n - i + 1], j);
            maxi = max(maxi, n - i + 1);
        }
    }

    //forn(i, n) cout << l[i] << " " << r[i] << endl;

    for(int i = 0; i < (1 << n); i++)
    {
        sum = 0;
        cur = 1;
        for(int j = 1; j < maxi; j++)
        {
            if (l[j] != INF)
            {
                if (cur == 1)
                {
                    sum += r[j] - cur;
                    cur = r[j];
                }
                else
                {
                    sum += cur - l[j];
                    cur = l[j];
                }
            }
            if ((i >> j) & 1) cur1 = m + 2;
            else cur1 = 1;
            sum += abs(cur - cur1);
            cur = cur1;
        }
        //if (!i) cout << sum << " ";
        if (l[maxi] == INF) ans = min(ans, sum);
        else
        {
            if (cur == 1) sum += r[maxi] - cur;
            else sum += cur - l[maxi];
            ans = min(ans, sum);
        }
        //cout << i << " " << sum << " " << cur << endl;
    }

    cout << ans + maxi - 1;

    return 0;
}