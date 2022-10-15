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

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    queue<list<int>> q;

    for (int i = 0; i < n; ++i)
    {
        list<int> L;
        L.push_back(i);
        while (i + 1 < n && gcd(a[i], a[i + 1]) > 1) L.push_back(++i);
        q.push(move(L));
    }

    vector<int> res;

    while (size(q) > 1)
    {
        auto L = move(q.front());
        q.pop();
        auto& R = q.front();
        int i = *rbegin(L), j = *begin(R);

        if (gcd(a[i], a[j]) == 1)
        {
            res.push_back(j);
            R.pop_front();
            if (empty(R)) q.pop();
            q.push(move(L));
        }
        else
        {
            L.splice(end(L), R);
            swap(L, R);
        }
    }

    auto L = move(q.front());
    q.pop();

    while (not empty(L) && gcd(a[*begin(L)], a[*rbegin(L)]) == 1)
    {
        res.push_back(*begin(L));
        L.pop_front();
    }

    cout << size(res);
    for (auto i : res) cout << " " << i + 1;
    cout << endl;
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}