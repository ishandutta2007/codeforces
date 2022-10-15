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
    int q; cin >> q;

    for (int t = 0; t < q; ++t)
    {
        int n; cin >> n;

        vvi T(2, vi(n));

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < n; ++j)
            {
                char c; cin >> c;
                if (c == '1' || c == '2')
                    T[i][j] = 0;
                else
                    T[i][j] = 1;
            }

        bool B = false;
        bool failed = false;
        for (int i = 0; i < n; ++i)
        {
            if (T[B][i] == 0)
                continue;
            else if (T[0][i] && T[1][i])
            {
                B = !B;
                continue;
            }
            else
            {
                failed = true;
                break;
            }
        }

        if (failed || B == false)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    exit(0);
}