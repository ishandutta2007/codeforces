#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        map<int, vi> H;

        for (int i = 0; i < n; ++i)
            H[b[i] - a[i]].pb(i);

        bool ans = true;

        if (H.size() > 2)
            ans = false;

        int pos = 0;
        for (auto [k, v] : H)
        {
            if (k < 0)
                ans = false;
            else if (k > 0)
            {
                pos++;
                for (int i = 1; i < (int)v.size(); ++i)
                    if (v[i] != v[i-1] + 1)
                        ans = false;
            }
        }

        if (pos > 1)
            ans = false;

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    exit(0);
}