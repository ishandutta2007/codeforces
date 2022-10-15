#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int p, n; cin >> p >> n;

    vector<int> bucket(p, 0);

    int ans = -1;

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x; x %= p;
        if (bucket[x]++)
        {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;

    exit(0);
}