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
    vi a(n);
    vi s(n + 1, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s[a[i]] = i;
    }
    vi L(n, 1);
    for (int x = n; x >= 1; --x)
    {
        int i = s[x];
        for (int j = i % x; j < n; j += x)
        {
            if (a[j] > a[i] && L[j])
            {
                L[i] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << (L[i] ? 'B' : 'A');
    cout << endl;

    exit(0);
}