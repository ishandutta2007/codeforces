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
    int h;
    cin >> h;

    vector<int> a(h + 1, 0);
    for (auto& x : a) cin >> x;

    bool perfect = true;
    for (int x = 2; x <= h; ++x)
    {
        if (a[x] > 1 && a[x - 1] > 1)
        {
            perfect = false;
            break;
        }
    }

    if (perfect)
    {
        cout << "perfect" << endl;
    }
    else
    {
        vector<int> p(1, 0), V(1, 1);
        for (int x = 1, cur = 2; x <= h; ++x)
        {
            int k = size(V);
            if (a[x - 1] > 1)
            {
                int u = V[k - 1], w = V[k - 2];
                for (int i = 0; i < a[x] - 1; ++i)
                {
                    p.push_back(u);
                    V.push_back(cur++);
                }
                p.push_back(w);
                V.push_back(cur++);
            }
            else
            {
                for (int i = 0; i < a[x]; ++i)
                {
                    p.push_back(V[k - 1]);
                    V.push_back(cur++);
                }
            }
        }

        cout << "ambiguous" << endl;
        for (auto u : p)
        {
            cout << u << " ";
        }
        cout << endl;

        cout << 0 << " ";
        for (int x = 1, last = 1, cur = 1; x <= h; ++x)
        {
            for (int i = 0; i < a[x]; ++i, ++cur) cout << last << " ";
            last = cur;
        }
        cout << endl;
    }

    exit(0);
}