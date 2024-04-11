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
    int q; cin >> q;
    while (q--)
    {
        int n, r; cin >> n >> r;

        vi x(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i];

        sort(x.rbegin(), x.rend());
        int c = 0;
        int d = 1000000;
        for (int i = 0; i < n; ++i)
        {
            if (x[i] >= d || x[i] - c <= 0)
                continue;
            else
            {
                d = x[i];
                c += r;
            }
        }

        cout << c / r << endl;
    }
    exit(0);
}