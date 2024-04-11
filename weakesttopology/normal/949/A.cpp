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
    cout << -1 << endl;
    exit(0);
}

int main()
{ _
    string s; cin >> s;

    int n = size(s);

    vector ans(0, vector(0, 0));

    queue<int> q[2];

    for (int i = 0; i < n; ++i)
    {
        int b = s[i] - '0';

        if (b == 0 && empty(q[b]))
        {
            q[0].push(size(ans));
            ans.push_back(vector(0, 0));
        }

        if (empty(q[b])) fail();

        int idx = q[b].front(); q[b].pop();

        ans[idx].push_back(i);

        q[b ^ 1].push(idx);
    }

    if (not empty(q[0])) fail();

    cout << size(ans) << endl;

    for (auto& v : ans)
    {
        cout << size(v);
        for (auto x : v) cout << " " << x + 1;
        cout << endl;
    }

    exit(0);
}