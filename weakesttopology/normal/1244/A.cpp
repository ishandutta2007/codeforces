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
        int a, b, c, d, k; cin >> a >> b >> c >> d >> k;

        int x = (a + c - 1) / c, y = (b + d - 1) / d;

        if (x + y <= k)
            cout << x << " " << y << endl;
        else
            cout << -1 << endl;
    }
    exit(0);
}