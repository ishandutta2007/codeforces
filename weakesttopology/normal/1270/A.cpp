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
    int t; cin >> t;
    while (t--)
    {
        int n, k1, k2; cin >> n >> k1 >> k2;

        int M1 = 0;
        for (int i = 0; i < k1; ++i)
        {
            int a; cin >> a;
            M1 = max(M1, a);
        }
        int M2 = 0;
        for (int i = 0; i < k2; ++i)
        {
            int a; cin >> a;
            M2 = max(M2, a);
        }

        if (M1 > M2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    exit(0);
}