#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

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

    vector op(2 * n, 0);

    for (auto& x : op)
    {
        char c; cin >> c;

        if (c == '+') x = -1;

        else cin >> x;
    }

    reverse(all(op));

    vector ans(0, 0);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto x : op)
    {
        if (x == -1)
        {
            if (empty(pq)) fail();
            ans.push_back(pq.top()); pq.pop();
        }
        else
        {
            if (not empty(pq) && pq.top() < x) fail();
            pq.push(x);
        }
    }

    reverse(all(ans));

    cout << "YES" << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;

    exit(0);
}