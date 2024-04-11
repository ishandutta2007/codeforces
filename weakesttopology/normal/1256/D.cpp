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
    int q; cin >> q;
    while (q--)
    {
        ll n, k; cin >> n >> k;
        set<ll> A[2] = { set<ll>(), set<ll>() };
        for (ll i = 0; i < n; ++i)
        {
            char c; cin >> c;
            A[c - '0'].insert(i);
        }

        vi ans;
        while (not (A[0].empty() || A[1].empty()))
        {
            ll diff = *A[0].begin() - ans.size();

            if (diff <= k)
            {
                ans.pb(0);
                A[0].erase(A[0].begin());
                k -= diff;
            }
            else
            {
                ans.pb(1);
                A[1].erase(A[1].begin());
            }
        }

        for (auto x : ans)
            cout << x;
        for (auto x : A[0])
            cout << 0;
        for (auto x : A[1])
            cout << 1;

        cout << endl;
    }
    exit(0);
}