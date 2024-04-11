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

void fail()
{
    cout << "NO" << endl;
    exit(0);
}

int main()
{ _
    int n; cin >> n;

    vector p(n, 0);
    for (auto& x : p) cin >> x;

    auto values = p;
    values.push_back(-1);

    sort(all(values)), values.erase(unique(all(values)), end(values));

    for (auto& x : p)
        x = (int)distance(begin(values), lower_bound(all(values), x));

    int t; cin >> t;

    vector negative(n, 0);

    for (int z = 0; z < t; ++z)
    {
        int i; cin >> i; --i;
        negative[i] = 1;
    }

    stack<int> stk;

    for (int i = n - 1; i >= 0; --i)
    {
        if (not negative[i] && not empty(stk) && stk.top() == p[i])
            stk.pop();
        else
        {
            stk.push(p[i]);
            p[i] *= -1;
        }
    }

    if (not empty(stk)) fail();

    cout << "YES" << endl;

    for (auto x : p)
        cout << values[abs(x)] * (x > 0 ? 1 : -1) << " ";
    cout << endl;

    exit(0);
}