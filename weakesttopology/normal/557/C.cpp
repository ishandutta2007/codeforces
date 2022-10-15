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
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int n; cin >> n;

    vii L(n);
    for (int i = 0; i < n; ++i)
        cin >> L[i].f;
    for (int i = 0; i < n; ++i)
        cin >> L[i].s;
    sort(L.begin(), L.end());

    vector<ll> D(n);
    D[0] = L[0].s;
    for (int i = 1; i < n; ++i)
        D[i] = D[i-1] + L[i].s;

    ll m = LINF;

    map<int, int> H;
    for (int i = 0; i < n; ++i)
    {
        int b = i;
        while (i + 1 < n && L[i].f == L[i+1].f)
            ++i;
        int e = i, h = e - b;

        ll cost = D[n - 1] - D[e];
        if (b > 0)
            cost += D[b - 1];

        for (auto iter = H.rbegin(); iter != H.rend(); ++iter)
        {
            int d = iter->f, f = iter->s;
            int c = min(f, h);
            cost -= d * c;
            h -= c;
        }

        m = min(m, cost);

        for (int j = b; j <= e; ++j)
        {
            H[L[j].s]++;
        }
    }

    cout << m << endl;

    exit(0);
}