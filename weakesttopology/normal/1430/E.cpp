#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
ll merge_sort(vector<T>& v, vector<T>& u, int l, int r)
{
    if (r <= l) return 0LL;
    int m = l + (r - l) / 2;
    ll res = merge_sort(v, u, l, m) + merge_sort(v, u, m + 1, r);
    int x = l, y = m + 1, z = l;
    while (x <= m && y <= r)
    {
        if (v[x] <= v[y])
            u[z++] = v[x++];
        else
            u[z++] = v[y++], res += m - x + 1;
    }
    while (x <= m) u[z++] = v[x++];
    while (y <= r) u[z++] = v[y++];
    while (l <= r) v[--z] = u[r--];
    return res;
}

template<typename T>
ll inversions(vector<T> v)
{
    vector<T> u = v;
    return merge_sort(v, u, 0, size(v) - 1);
}

int main()
{ _
    int n; cin >> n;
    string s; cin >> s;

    stack<int> st[26];

    for (int i = 0; i < n; ++i)
        st[s[i] - 'a'].push(n - 1 - i);

    vector a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int idx = s[i] - 'a';
        a[i] = st[idx].top(); st[idx].pop();
    }

    ll ans = inversions(a);

    cout << ans << endl;

    exit(0);
}