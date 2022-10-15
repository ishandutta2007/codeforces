#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';

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
    int n, m; cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> sum(n, 0);
    sum[0] = a[0];
    for (int i = 1; i < n; ++i)
        sum[i] = sum[i-1] + a[i];

    auto dp = sum;
    for (int i = m; i < n; ++i)
        dp[i] = dp[i - m] + sum[i];

    for (auto x : dp)
        cout << x << " ";
    cout << endl;

    exit(0);
}