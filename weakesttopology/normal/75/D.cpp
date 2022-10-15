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

int main()
{ _
    int n, m; cin >> n >> m;
    vector<tuple<ll, ll, ll, ll>> S(n, {0, -INF, -INF, -INF});
    for (int i = 0; i < n; ++i)
    {
        int l; cin >> l;
        vi A = vi(l);
        ll sum = 0;
        for (int j = 0; j < l; ++j)
        {
            cin >> A[j];
            get<0>(S[i]) += A[j];

            sum += A[j];
            get<1>(S[i]) = max(get<1>(S[i]), sum);
            sum = max(sum, 0LL);

            get<2>(S[i]) = max(get<2>(S[i]), get<0>(S[i]));
        }

        sum = 0;
        for (int j = l - 1; j >= 0; --j)
        {
            sum += A[j];
            get<3>(S[i]) = max(get<3>(S[i]), sum);
        }
    }


    vi B(m);
    READ(B);
    for (int j = 0; j < m; ++j)
        B[j]--;

    ll M = -INF;
    ll sum = 0;
    for (int j = 0; j < m; ++j)
    {
        M = max(get<1>(S[B[j]]), M);

        ll a = get<0>(S[B[j]]);
        ll b = get<2>(S[B[j]]);
        ll c = get<3>(S[B[j]]);

        M = max(M, sum + b);

        if (sum + a >= c)
            sum += a;
        else
            sum = c;

        M = max(M, sum);
        sum = max(sum, 0LL);
    }

    cout << M << endl;

    exit(0);
}