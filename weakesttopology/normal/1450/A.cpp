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

string solve()
{
    int n; cin >> n;
    string s; cin >> s;
    sort(all(s));
    return s;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}