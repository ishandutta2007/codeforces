#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

bool query(int u, int v)
{
    static bool yes = false;
    assert(not yes);
    u += 1, v += 1;
    cout << "? " << u << " " << v << endl;
    string res;
    cin >> res;
    return res == "Yes";
}

int main()
{ _
    int n;
    cin >> n;

    vector<int> k(n);
    for (auto& x : k) cin >> x;

    vector<int> V(n);
    iota(all(V), 0);
    sort(all(V), [&k](int u, int v){ return k[u] > k[v]; });

    int u = 0, v = 0;

    for (int i = 0; i < n && u == 0; ++i)
    {
        for (int j = n - 1; j > i && u == 0; --j)
        {
            if (query(V[i], V[j]))
            {
                u = V[i] + 1, v = V[j] + 1;
                break;
            }
        }
    }

    cout << "! " << u << " " << v << endl;

    exit(0);
}