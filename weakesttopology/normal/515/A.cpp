#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int a, b, s; cin >> a >> b >> s;

    bool cond1 = abs(a) + abs(b) <= s;
    bool cond2 = (abs(a) + abs(b)) % 2 == s % 2;

    if (cond1 && cond2) cout << "Yes\n";
    else cout << "No\n";

    exit(0);
}