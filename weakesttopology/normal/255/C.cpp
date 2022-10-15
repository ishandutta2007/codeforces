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

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};

int main()
{ _
    int n; cin >> n;
    vi b(n);

    unordered_map<int, int, custom_hash> sz;
    unordered_map<int, int, custom_hash> l;

    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        sz[b[i]] = 0;
        l[b[i]] = 0;
    }

    map<int, int> f;

    int m = 1;
    for (int i = 0; i < n; ++i)
    {
        m = max(m, ++f[b[i]]);

        for (auto [k, v] : sz)
            sz[k] = l[k] = 0;

        for (int j = i; j < n; ++j)
        {
            if (b[j] != b[i])
                sz[b[j]] += (l[b[i]] > l[b[j]]);

            l[b[j]] = j + 1;
        }

        for (auto [k, v] : sz)
        {
            m = max(m, 2 * v + (l[k] < l[b[i]]));
        }
    }


    cout << m << endl;

    exit(0);
}