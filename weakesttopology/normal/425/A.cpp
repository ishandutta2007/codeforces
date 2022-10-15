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

template<typename T>
struct better_queue : public priority_queue<T>
{
    void clear() { this->c.clear(); }
};

int main()
{ _
    int n, k; cin >> n >> k;

    vector a(n, 0);

    for (auto& x : a) cin >> x;

    int ans = -INF;

    better_queue<int> pqmax, pqmin;

    auto mustswap = [&]()
    {
        if (empty(pqmax) || empty(pqmin)) return false;
        return pqmax.top() > -pqmin.top();
    };

    for (int len = 1; len <= n; ++len)
    {
        for (int i = 0; i + len <= n; ++i)
        {
            pqmax.clear(), pqmin.clear();

            for (int j = 0; j < n; ++j) if (j < i || j >= i + len)
                pqmax.push(a[j]);

            int sum = 0;

            for (int j = i; j < i + len; sum += a[j++])
                pqmin.push(-a[j]);

            for (int z = 0; z < k && mustswap(); ++z)
            {
                sum += pqmax.top() + pqmin.top();
                pqmax.pop(), pqmin.pop();
            }

            ans = max(ans, sum);
        }
    }

    cout << ans << endl;

    exit(0);
}