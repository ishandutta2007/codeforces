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

int n;
vector<pii> Vec;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    Vec.resize(n + 1);
    fore(i, n)
    {
        cin >> Vec[i].f >> Vec[i].sec;
        if (Vec[i].f != Vec[i].sec)
        {
            cout << "rated";
            exit(0);
        }
    }

    for(int i = 1; i < n; i++) if (Vec[i].f > Vec[i - 1].f)
    {
        cout << "unrated";
        exit(0);
    }

    cout << "maybe";


    return 0;
}