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
    vector<ll> p(40), s(40);
    p[0] = 1, s[0] = 1;
    for (int i = 1; i < 40; i++)
    {
        p[i] = 3 * p[i-1];
        s[i] = p[i] + s[i-1];
    }

    int q; cin >> q;
    while (q--)
    {
        ll n; cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        int e = 39;
        while (s[e - 1] >= n)
            e--;

        ll m = s[e];
        for (int i = e - 1; i >= 0; --i)
        {
            if (m - p[i] >= n)
                m -= p[i];
        }

        cout << m << endl;
    }
    exit(0);
}