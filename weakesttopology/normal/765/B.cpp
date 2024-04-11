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
    string s;
    cin >> s;

    int a[26];
    fill(all(a), INF);

    for (int i = size(s) - 1; i >= 0; --i) a[s[i] - 'a'] = i;

    cout << (is_sorted(all(a)) ? "YES" : "NO") << endl;

    exit(0);
}