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
    while(q--)
    {
        int n; cin >> n;
        vi p(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
            p[i]--;
        }

        vi a(n, -1);
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != -1)
                continue;

            int c = 1, j = p[i];
            while (j != i)
            {
                j = p[j];
                c++;
            }
            j = p[i];
            a[i] = c;
            while (j != i)
            {
                j = p[j];
                a[j] = c;
            }
        }

        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
    exit(0);
}