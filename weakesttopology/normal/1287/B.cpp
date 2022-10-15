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

int main()
{ _
    int n, k; cin >> n >> k;
    vector<string> D(n);
    READ(D);
    sort(ALL(D));

    map<string, ll> H;

    for (int i = 0; i < n; ++i)
        H[D[i]]++;

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
        {
            string X;
            for (int l = 0; l < k; ++l)
            {
                if (D[i][l] == D[j][l])
                    X.pb(D[i][l]);
                else
                {
                    if (D[i][l] != 'S' && D[j][l] != 'S')
                        X.pb('S');
                    if (D[i][l] != 'E' && D[j][l] != 'E')
                        X.pb('E');
                    if (D[i][l] != 'T' && D[j][l] != 'T')
                        X.pb('T');
                }
            }

            ans += H[X];
        }

    cout << ans / 3 << endl;

    exit(0);
}