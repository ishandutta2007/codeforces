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
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vi S;

bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= n || j < i)
        return false;

    int R = S[j];
    if (i > 0)
        R -= S[i - 1];

    return R == j - i + 1;
}

int main()
{ _
    cin >> n;
    vi a(n);
    READ(a);
    int sum = 0;
    int M = 1;
    S.assign(n, 0);
    for (int i = 1; i < n; ++i)
    {
        bool x = a[i] > a[i - 1];
        sum += x;
        sum *= x;
        M = max(M, sum + 1);
        S[i] += S[i - 1] + x;
    }

    for (int i = 1; i + 1 < n; ++i)
    {
        if (a[i - 1] >= a[i + 1])
            continue;

        int l = i - 1;
        for (int b = l; b > 0; b /= 2)
            while (l - b >= 0 && S[i - 1] - S[l - b] == (i - 1) - (l - b))
                l -= b;

        int r = i + 1;
        for (int b = n - r - 1; b > 0; b /= 2)
            while (r + b < n && S[r + b] - S[i + 1] == (r + b) - (i + 1))
                r += b;

        M = max(M, r - l);
    }

    cout << M << endl;

    exit(0);
}