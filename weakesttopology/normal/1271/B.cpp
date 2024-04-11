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
    int n; cin >> n;
    vi A(n);
    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        A[i] = c == 'B';
    }

    int k = 0;
    vi P;
    for (int i = 0; i + 1 < n; ++i)
    {
        if (A[i] % 2)
        {
            k++;
            A[i]++;
            A[i + 1]++;
            P.pb(i);
        }
    }

    if (A[n - 1] % 2 == 0)
    {
        cout << k << endl;
        for (auto i : P)
            cout << i + 1 << " ";
        cout << endl;
    }
    else if (A[n - 1] % 2 && n % 2)
    {
        cout << k + n / 2 << endl;
        for (auto i : P)
            cout << i + 1 << " ";
        for (int i = 0; i + 1 < n; i += 2)
            cout << i + 1 << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;

    exit(0);
}