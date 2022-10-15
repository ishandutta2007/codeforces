#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    char a[] = "abc";

    int t; cin >> t;

    while (t--)
    {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; ++i) cout << a[i % 3];
        cout << endl;
    }

    exit(0);
}