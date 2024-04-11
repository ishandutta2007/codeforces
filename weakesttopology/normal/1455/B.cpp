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
    int t; cin >> t;

    while (t--)
    {
        int x; cin >> x;

        int ans = 0, jump = 0;

        int k = 1;

        while (jump < x) jump += k++, ans += 1;

        ans += x == jump - 1;

        cout << ans << endl;
    }

    exit(0);
}