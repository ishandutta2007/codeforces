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
    bool up = true;
    vi b(n);
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;

        if (a % 2)
        {
            b[i] = a > 0 ? a / 2 + up : a / 2 - 1 + up;
            up = !up;
        }
        else
            b[i] = a / 2;
    }
    for (auto x : b)
        cout << x << endl;

    exit(0);
}