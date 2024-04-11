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
    ll n; cin >> n;

    ll N = n;
    vector<ll> P;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            while(N % i == 0)
                N /= i;

            P.pb(i);
        }
    }

    if (N > 2)
        P.pb(N);

    if (P.size() == 1)
        cout << P[0] << endl;
    else if (P.size() > 1)
        cout << 1 << endl;
    else
        cout << n << endl;

    exit(0);
}