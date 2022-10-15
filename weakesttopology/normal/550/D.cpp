#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
#define SZ(X) (int)X.size()

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

void print_edge(int i, int j)
{
    cout << i + 1 << " " << j + 1 << endl;
}

int main()
{ _
    int k; cin >> k;
    if (k == 1)
    {
        cout << "YES\n2 1\n1 2\n";
        exit(0);
    }
    if (k % 2 == 0)
    {
        cout << "NO" << endl;
        exit(0);
    }

    cout << "YES" << endl;

    cout << 2 * (k - 1) + 6 << " " << (k - 1) * (k - 3) + 4 * k - 2 + 2 * (k - 1) + 1 << endl;

    for (int i = 0; i < k - 1; ++i)
        for (int j = i + 1 + (i + 1) % 2; j < k - 1; ++j)
        {
            print_edge(i, j);
            print_edge(k - 1 + i, k - 1 + j);
        }

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < k - 1; ++j)
        {
            print_edge(2 * (k - 1) + i, j);
            print_edge(2 * (k - 1) + 2 + i, k - 1 + j);
        }

        print_edge(2 * (k - 1) + 2 * i, 2 * (k - 1) + 2 * i + 1);
    }

    for (int j = 0; j < k - 1; ++j)
    {
        print_edge(2 * (k - 1) + 4, j);
        print_edge(2 * (k - 1) + 5, (k - 1) + j);
    }

    print_edge(2 * (k - 1) + 4, 2 * (k - 1) + 5);

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/