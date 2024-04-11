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

bool check(int a, int b)
{
    return 2 * b - a >= 0 && (2 * b - a) % 3 == 0;
}

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;

        if (check(a, b) && check(b, a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    exit(0);
}