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
    while (q--)
    {
        int n; cin >> n;
        vi p(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i];

        int w = n - 1;

        set<ii> I;

        for (int s = 0; s < n && w > 0; ++s)
        {
            int j = s;
            for (int i = s + 1; i < n && i - s <= w && I.count({i - 1, i}) == 0; ++i)
                if (p[i] < p[j] && p[i] != -1)
                    j = i;
            int t = p[j];
            for (int i = j; i > s; --i)
            {
                I.insert({i - 1, i});
                p[i] = p[i-1];
            }
            p[s] = t;
            w -= j - s;
        }

        for (int i = 0; i < n; ++i)
            cout << p[i] << " ";
        cout << endl;
    }
    exit(0);
}