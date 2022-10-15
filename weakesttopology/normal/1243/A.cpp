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
    int k; cin >> k;
    while (k--)
    {
        int n; cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.rbegin(), a.rend());

        int m = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i + 1 <= a[i])
                m = i + 1;
        }

        cout << m << endl;
    }
    exit(0);
}