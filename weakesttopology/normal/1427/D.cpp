#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
int size(const auto& X) { return (int)std::size(X); }

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void apply(auto& c, auto D)
{
    vector<int> nxt;

    // for (auto x : D)
    //     cerr << x << " ";
    // cout << endl;

    while (not D.empty())
    {
        int d = D.back(); D.pop_back();
        nxt.insert(end(nxt), end(c) - d, end(c));
        c.erase(end(c) - d, end(c));
    }

    c = nxt;
}

int main()
{ _
    int n; cin >> n;

    vector c(n, 0);
    for (int i = 0; i < n; ++i) cin >> c[i];

    vector op(0, vector(0, 0));

    for (int l = 0, r = n - 1, b = 0; l < r; b = !b)
    {
        auto iterl = begin(c) + l, iterr = begin(c) + r;

        int m = 0;
        if (b == 0)
            m = (int)distance(begin(c), max_element(iterl, iterr + 1));
        else
            m = (int)distance(begin(c), min_element(iterl, iterr + 1));

        vector D(0, 0);
        for (int i = 0; i < l; ++i) D.push_back(1);
        D.push_back(m - l + 1);
        if (m < r) D.push_back(r - m);
        for (int i = r + 1; i < n; ++i) D.push_back(1);

        if (D.size() > 1) op.push_back(D);

        // debug(l);
        // debug(r);
        // debug(m);
        // debug(c[m]);

        apply(c, D);

        // for (auto x : c) cerr << x << " ";
        // cerr << endl;

        int lnxt = n - 1 - r, rnxt = n - (l + 1) - 1;

        l = lnxt, r = rnxt;
    }

    if (not is_sorted(all(c))) op.push_back(vector(n, 1));

    cout << op.size() << endl;
    for (auto& D: op)
    {
        cout << D.size();
        for (auto d : D) cout << " " << d;
        cout << endl;
    }

    // for (auto x : c) cerr << x << " ";
    // cerr << endl;

    exit(0);
}