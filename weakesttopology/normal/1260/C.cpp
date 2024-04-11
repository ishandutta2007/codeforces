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
        ll r, b, k; cin >> r >> b >> k;
        if (r > b)
            swap(r, b);

        if (b - __gcd(r, b) > r * (k - 1))
            cout << "REBEL\n";
        else
            cout << "OBEY\n";
    }
    exit(0);
}