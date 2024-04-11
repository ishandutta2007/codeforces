#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

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
    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        vi a(n);
        map<int, vi> H;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            H[a[i]].pb(i);
        }

        int l = -1, r = INF - 10;
        for (auto [k, v] : H)
        {
            if (v.size() > 1)
                for (int i = 1; i < (int)v.size(); ++i)
                    if (v[i] - v[i-1] < r - l)
                    {
                        l = v[i-1];
                        r = v[i];
                    }
        }

        if (l != -1)
            cout << r - l + 1 << endl;
        else
            cout << -1 << endl;
    }
    exit(0);
}