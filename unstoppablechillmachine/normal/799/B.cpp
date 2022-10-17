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
#define forn(i, n) for (int i = 1; i <= n; i++)
#define fore(i, n) for (int i = 0; i < n; i++)

int n, aa, min1, cost[MAXN], p, mini;
set<int>::iterator it;
vector<set<int> > st;
pii a[MAXN];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    st.resize(7);
    forn(i, n)
    {
        cin >> cost[i];
    }

    forn(i, n)
    {
        cin >> a[i].f;
    }

    forn(i, n)
    {
        cin >> a[i].sec;
    }

    forn(i, n)
    {
        if (a[i].f > a[i].sec) swap(a[i].f, a[i].sec);
        if (a[i].f == 1 && a[i].sec == 1) st[1].insert(cost[i]);
        if (a[i].f == 1 && a[i].sec == 2) st[2].insert(cost[i]);
        if (a[i].f == 1 && a[i].sec == 3) st[3].insert(cost[i]);
        if (a[i].f == 2 && a[i].sec == 2) st[4].insert(cost[i]);
        if (a[i].f == 2 && a[i].sec == 3) st[5].insert(cost[i]);
        if (a[i].f == 3 && a[i].sec == 3) st[6].insert(cost[i]);
    }

    //forn(i, 6) cout << st[i].size() << " " << *st[i].begin() << endl;
    cin >> p;
    forn(j, p)
    {
        cin >> aa;
        min1 = INF;
        if (aa == 1)

        {
            forn(i, 3)
            {
                if (!st[i].empty())
                {
                    it = st[i].begin();
                    if (*it < min1) mini = i;
                    min1 = min(min1, *it);
                    //st.erase(st.begin());
                }
            }
        }
        else if (aa == 2)
        {
            for(int i = 2; i <= 5; i++)
            {
                if (i == 3) continue;
                if (!st[i].empty())
                {
                    it = st[i].begin();
                    if (*it < min1) mini = i;
                    min1 = min(*it, min1);
                    //st.erase(st.begin());
                }
            }
        }
        else
        {
            for (int i = 3; i <= 6; i++)
            {
                if (i == 4) continue;

                if (!st[i].empty())
                {
                    it = st[i].begin();
                    if (*it < min1) mini = i;
                    min1 = min(*it, min1);
                    //st.erase(st.begin());
                }
            }
        }

        if (min1 == INF) cout << -1 << " ";
        else
        {
            cout << min1 << " ";
            st[mini].erase(*st[mini].begin());
        }
    }






    return 0;
}