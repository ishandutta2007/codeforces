#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9 + 7;
ll const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-9;

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

ll p, x, y, s, a;
set<ll> st;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> p >> x >> y;
    for(int i = 0;; i++)
    {
        st.clear();
        s = x - 50 * i;
        a = (s / 50) % 475;
        if (s < y) break;
        forn(j, 25)
        {
            a = (a * 96 + 42) % 475;
            st.insert(26 + a);
        }
        if (st.find(p) != st.end())
        {
            cout << 0;
            exit(0);
        }
    }

    for(int i = 1;; i++)
    {
        s = x + 100 * i;
        st.clear();
        a = (s / 50) % 475;
        //if (s < y) break;
        forn(j, 25)
        {
            a = (a * 96 + 42) % 475;
            st.insert(26 + a);
        }
        if (st.find(p) != st.end())
        {
            cout << i;
            exit(0);
        }

        s = x + 100 * i - 50;
        st.clear();
        a = (s / 50) % 475;
        //if (s < y) break;
        forn(j, 25)
        {
            a = (a * 96 + 42) % 475;
            st.insert(26 + a);
        }
        if (st.find(p) != st.end())
        {
            cout << i;
            exit(0);
        }
    }


    return 0;
}