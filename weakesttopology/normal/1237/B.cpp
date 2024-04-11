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
    vi s(n, 0);

    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a; a--;
        s[a] = i;
    }

    vi b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        b[i]--;
    }


    int m = INF;
    int sum = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        sum += m < s[b[i]];
        m = min(s[b[i]], m);
    }

    cout << sum << endl;

    exit(0);
}