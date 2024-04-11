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
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int x = -1;
        for (int i = 0; i < n; ++i)
        {
            char c; cin >> c;
            if (c == '1' && (x == -1 || min(x, n - 1 - x) > min(i, n - 1 - i)))
                x = i;
        }

        if (x == -1)
            cout << n << endl;
        else
            cout << 2 * max(x + 1, n - x) << endl;
    }
    exit(0);
}