#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};

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
    int n, m; cin >> n >> m;

    vector<string> V(n);

    for (int i = 0; i < n; ++i)
        cin >> V[i];

    int r = 0;
    vi G(n, 0);
    for (int j = 0; j < m; ++j)
    {
        bool lex = true;
        vi G1(n, 0);

        for (int i = 1; i < n; ++i)
        {
            if (G[i] == G[i - 1] && V[i][j] < V[i-1][j])
            {
                lex = false;
                break;
            }
        }

        if (lex)
        {
            int g = 0;
            for (int i = 1; i < n; ++i)
            {
                g += (G[i] == G[i-1]) && (V[i][j] > V[i-1][j]);

                G1[i] = G[i] + g;
            }

            G = G1;
        }
        else
            r++;
    }

    cout << r << endl;

    exit(0);
}