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
    while(q--)
    {
        int h, n; cin >> h >> n;
        vi p(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        p.pb(0);
        p.pb(0);
        sort(p.begin(), p.end());

        int N = p.size();
        vi C(N, 0);

        for (int i = 2; i < N; ++i)
        {
            if (p[i-2] >= p[i-1] - 1)
                C[i] = min(1 + C[i-1], C[i-2]);
            else
                C[i] = 1 + C[i - 1];
        }

        cout << C.back() << endl;
    }
    exit(0);
}