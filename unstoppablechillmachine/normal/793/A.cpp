#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF=1000000000;
ll const BINF=1000000000000000000;
int const MAXN = 1e6  + 10;
ld const EPS = -0.0000000000000001;

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

vector<ll> Vec;
ll n, k, sum;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> k;
    Vec.resize(n);
    fore(i, n)
    {
        cin >> Vec[i];
    }

    sort(Vec.begin(), Vec.end());
    for (int i = 1; i < n; i++)
    {
        if ((Vec[i] - Vec[0]) % k == 0) sum += (Vec[i] - Vec[0]) / k;
        else
        {
            cout << -1;
            exit(0);
        }
    }

    cout << sum;



    return 0;
}