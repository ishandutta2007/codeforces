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
    vi x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    for (int i = 1; i < n; ++i)
    {
        x[i] = x[i] - x[0];
        y[i] = y[i] - y[0];
    }
    x[0] = y[0] = 0;

    int g = gcd(x[1], y[1]);
    for (int i = 2; i < n; ++i)
        g = gcd(x[i], gcd(y[i], g));

    bool odd_x = false;
    bool odd_y = false;
    for (int i = 0; i < n; ++i)
    {
        x[i] /= g; odd_x = odd_x || x[i] % 2;
        y[i] /= g; odd_y = odd_y || y[i] % 2;
    }

    set<int> A;
    for (int i = 0; i < n; ++i)
        if ((x[i] + y[i]) % 2)
            A.insert(i + 1);

    if (A.size() == 0)
    {
        if (odd_x)
            for (int i = 0; i < n; ++i)
            {
                int a = x[i], b = y[i];
                x[i] = (a - b) / 2;
                y[i] = (a + b) / 2;
            }
        else if(odd_y)
            for (int i = 0; i < n; ++i)
            {
                int a = x[i], b = y[i];
                x[i] = (a + b) / 2;
                y[i] = (a - b) / 2;
            }

        for (int i = 0; i < n; ++i)
            if ((x[i] + y[i]) % 2)
                A.insert(i + 1);
    }

    cout << A.size() << endl;
    for (auto z : A)
        cout << z << " ";
    cout << endl;

    exit(0);
}