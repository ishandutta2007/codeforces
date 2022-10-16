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
    int n; cin >> n;

    vii R(n);

    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        R[i].f = a + b + c + d;
        R[i].s = -(i + 1);
    }

    sort(R.rbegin(), R.rend());

    for (int i = 0; i < n; ++i)
    {
        if (R[i].s == -1)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    exit(0);
}