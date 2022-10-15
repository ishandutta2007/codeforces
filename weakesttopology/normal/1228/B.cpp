#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    ll h, w; cin >> h >> w;
    vector<ll> r(h); vector<ll> c(w);

    for (ll i = 0; i < h; ++i)
        cin >> r[i];
    for (ll j = 0; j < w; ++j)
        cin >> c[j];

    int G[1000][1000];

    for (ll i = 0; i < h; ++i)
        for (ll j = 0; j < w; ++j)
            G[i][j] = 0;

    ll sum = 0;

    for (ll i = 0; i < h; ++i)
    {
        for (ll j = 0; j < r[i]; ++j)
        {
            if (G[i][j] == 0)
            {
                sum += 1;
                G[i][j] = 1;
            }
            else if (G[i][j] == -1)
            {
                cout << 0 << endl;
                exit(0);
            }
        }
        if (r[i] < w)
        {
            if (G[i][r[i]] == 0)
            {
                sum += 1;
                G[i][r[i]] = -1;
            }
            else if (G[i][r[i]] == 1)
            {
                cout << 0 << endl;
                exit(0);
            }
        }
    }
    for (ll j = 0; j < w; ++j)
    {
        for (ll i = 0; i < c[j]; ++i)
        {
            if (G[i][j] == 0)
            {
                sum += 1;
                G[i][j] = 1;
            }
            else if (G[i][j] == -1)
            {
                cout << 0 << endl;
                exit(0);
            }
        }
        if (c[j] < h)
        {
            if (G[c[j]][j] == 0)
            {
                sum += 1;
                G[c[j]][j] = -1;
            }
            else if (G[c[j]][j] == 1)
            {
                cout << 0 << endl;
                exit(0);
            }
        }
    }

    ll numways = 1;
    ll mod = 1000000000 + 7;

    for (ll e = 0; e < h * w - sum; ++e)
    {
        numways = 2 * numways % mod;
    }

    cout << numways << endl;

    exit(0);
}